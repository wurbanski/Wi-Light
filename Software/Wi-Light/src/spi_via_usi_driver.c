
#include "spi_via_usi_driver.h"
#include <util/delay_basic.h>

/*! \brief  Data input register buffer.
 *
 *  Incoming bytes are stored in this byte until the next transfer is complete.
 *  This byte can be used the same way as the SPI data register in the native
 *  SPI module, which means that the byte must be read before the next transfer
 *  completes and overwrites the current value.
 */
unsigned char storedUSIDR;
uint8_t TX_ADDRESS[TX_ADR_WIDTH]  = {0x34,0x43,0x10,0x10,0x01};
uint8_t LED_ON = 0x00;

/*! \brief  Driver status bit structure.
 *
 *  This struct contains status flags for the driver.
 *  The flags have the same meaning as the corresponding status flags
 *  for the native SPI module. The flags should not be changed by the user.
 *  The driver takes care of updating the flags when required.
 */
struct usidriverStatus_t {
	unsigned char masterMode : 1;       //!< True if in master mode.
	unsigned char transferComplete : 1; //!< True when transfer completed.
	unsigned char writeCollision : 1;   //!< True if put attempted during transfer.
};

volatile struct usidriverStatus_t spiX_status; //!< The driver status bits.



/*! \brief  Timer/Counter 0 Compare Match Interrupt handler.
 *
 *  This interrupt handler is only enabled when transferring data
 *  in master mode. It toggles the USI clock pin, i.e. two interrupts
 *  results in one clock period on the clock pin and for the USI counter.
 */

ISR(TIMER0_COMPA_vect)
{
	USICR ^= (1<<USITC);	// Toggle clock output pin.
}

void delay_ms(uint16_t ms){
	while (ms > 0) {
		_delay_loop_2(F_CPU/4000);
		ms--;
	}
}
void LED_ON_f()
{
	LED_ON = 1;
}
void LED_OFF()
{
	LED_ON = 0;
}
void CSN_L()
{
	PORTB &= ~(1 << USI_CSN_PIN);
}
void CSN_H()
{
	PORTB |= (1 << USI_CSN_PIN);
}
void CE_L()
{
	PORTB &= ~(1 << USI_CE_PIN);
}
void CE_H(void)
{
	PORTB |= (1 << USI_CE_PIN);
}

/*! \brief  USI Timer Overflow Interrupt handler.
 *
 *  This handler disables the compare match interrupt if in master mode.
 *  When the USI counter overflows, a byte has been transferred, and we
 *  have to stop the timer tick.
 *  For all modes the USIDR contents are stored and flags are updated.
 */

ISR(USI_OVF_vect)
{
	//test
	// Master must now disable the compare match interrupt
	// to prevent more USI counter clocks.
	if( spiX_status.masterMode == 1 ) {
		TIMSK &= ~(1<<OCIE0A);
	}
	
	// Update flags and clear USI counter
	USISR = (1<<USIOIF);
	spiX_status.transferComplete = 1;
	//PORTB |= (1 << USI_CSN_PIN);

	// Copy USIDR to buffer to prevent overwrite on next transfer.
	
	storedUSIDR = USIDR;
}

/*! \brief  Initialize USI as SPI master.
 *
 *  This function sets up all pin directions and module configurations.
 *  Use this function initially or when changing from slave to master mode.
 *  Note that the stored USIDR value is cleared.
 *
 *  \param spi_mode  Required SPI mode, must be 0 or 1.
 */
void spiX_initmaster( char spi_mode )
{
	// Configure port directions.
	USI_DIR_REG |= (1<<USI_DATAOUT_PIN) | (1<<USI_CLOCK_PIN); // Outputs.
	USI_DIR_REG &= ~(1<<USI_DATAIN_PIN);                      // Inputs.
	USI_OUT_REG |= (1<<USI_DATAIN_PIN);                       // Pull-ups.
	
	// Configure USI to 3-wire master mode with overflow interrupt.
	USICR = (1<<USIOIE) | (1<<USIWM0) |
	        (1<<USICS1) | (spi_mode<<USICS0) |
	        (1<<USICLK);

	// Enable 'Clear Timer on Compare match' and init prescaler.
	TCCR0A = (1<<WGM01);
	TCCR0B |= TC0_PS_SETTING; //clock select
	
	// Init Output Compare Register.
	OCR0A = TC0_COMPARE_VALUE;
	
	// Init driver status register.
	spiX_status.masterMode       = 1;
	spiX_status.transferComplete = 0;
	spiX_status.writeCollision   = 0;
	
	storedUSIDR = 0;
}

void spiX_init_slavemodule()
{
	USI_DIR_REG |= (1<<USI_CSN_PIN);
	//PORTB &= ~(1 << USI_CE_PIN); 
	PORTB |= (1 << USI_CSN_PIN); 
}
void spiX_free_slavemodule()
{
	{
		//PORTB |= (1 << USI_CE_PIN);
		if (LED_ON) PORTB |= (1 << USI_CSN_PIN);
		else PORTB &= ~(1 << USI_CSN_PIN);
	}
}

/*! \brief  Initialize USI as SPI slave.
 *
 *  This function sets up all pin directions and module configurations.
 *  Use this function initially or when changing from master to slave mode.
 *  Note that the stored USIDR value is cleared.
 *
 *  \param spi_mode  Required SPI mode, must be 0 or 1.
 */
void spiX_initslave( char spi_mode )
{
	// Configure port directions.
	USI_DIR_REG |= (1<<USI_DATAOUT_PIN);                      // Outputs.
	USI_DIR_REG &= ~(1<<USI_DATAIN_PIN) | (1<<USI_CLOCK_PIN); // Inputs.
	USI_OUT_REG |= (1<<USI_DATAIN_PIN) | (1<<USI_CLOCK_PIN);  // Pull-ups.
	
	// Configure USI to 3-wire slave mode with overflow interrupt.
	USICR = (1<<USIOIE) | (1<<USIWM0) |
	        (1<<USICS1) | (spi_mode<<USICS0);
	
	// Init driver status register.
	spiX_status.masterMode       = 0;
	spiX_status.transferComplete = 0;
	spiX_status.writeCollision   = 0;
	
	storedUSIDR = 0;
}



/*! \brief  Put one byte on bus.
 *
 *  Use this function like you would write to the SPDR register in the native SPI module.
 *  Calling this function in master mode starts a transfer, while in slave mode, a
 *  byte will be prepared for the next transfer initiated by the master device.
 *  If a transfer is in progress, this function will set the write collision flag
 *  and return without altering the data registers.
 *
 *  \returns  0 if a write collision occurred, 1 otherwise.
 */
char spiX_put( unsigned char val )
{
	
	// Check if transmission in progress,
	// i.e. USI counter unequal to zero.
	if( (USISR & 0x0F) != 0 ) {
		// Indicate write collision and return.
		spiX_status.writeCollision = 1;
		return 1;
	}
	
	// Reinit flags.
	spiX_status.transferComplete = 0;
	spiX_status.writeCollision = 0;

	// Put data in USI data register.
	USIDR = val;
	
	// Master should now enable compare match interrupts.
	if( spiX_status.masterMode == 1 ) {
		TIFR |= (1<<OCF0A);   // Clear compare match flag.
		TIMSK |= (1<<OCIE0A); // Enable compare match interrupt.
	}

	if( spiX_status.writeCollision == 0 ) return 1;
	return 0;
}



/*! \brief  Get one byte from bus.
 *
 *  This function only returns the previous stored USIDR value.
 *  The transfer complete flag is not checked. Use this function
 *  like you would read from the SPDR register in the native SPI module.
 */
unsigned char spiX_get()
{
	return storedUSIDR;
}



/*! \brief  Wait for transfer to complete.
 *
 *  This function waits until the transfer complete flag is set.
 *  Use this function like you would wait for the native SPI interrupt flag.
 */
void spiX_wait()
{
	do {} while( spiX_status.transferComplete == 0 );
}
uint8_t NRF_GetRegCommand(uint8_t Reg, uint8_t Operation)
{
	uint8_t OperationMask;

	OperationMask = (Operation ? REGISTER_WRITE : REGISTER_READ);
	return (OperationMask | (REGISTER_MASK & Reg));
}
void NRF_WriteRegData(uint8_t RegCommand, uint8_t* pData, uint8_t DataSize)
{
	uint8_t ii;
	CSN_H();
	delay_ms(3);
	CSN_L();
	spiX_put(RegCommand);
	spiX_wait();
	for(ii = 0; ii < DataSize; ii++)
	{
		spiX_put(pData[ii]);
		spiX_wait();
	}
	CSN_H();
}
void NRF_WriteReg(uint8_t RegCommand, uint8_t Value)
{
	CSN_H();
	delay_ms(3);
	CSN_L();
	spiX_put(RegCommand);
	spiX_wait();
	spiX_put(Value);
	spiX_wait();
	CSN_H();
}
void NRF_PowerUpRX(void)
{
	uint8_t RegValue;
	//CE_L();
	//can be done by checking every time the real value of register as shown below
	//RegValue = NRF_ReadReg(NRF_GetRegCommand(CONFIG, READ));
	RegValue = CONFIG_DEFAULT | ((1 << PWR_UP) | (1 << PRIM_RX));
	NRF_WriteReg(NRF_GetRegCommand(CONFIG, WRITE), RegValue);
	//CE_H();
}
void NRF_configure_RX()
{
	delay_ms(1);
	// enter standby mode
	//CE_L();

	// set receiver address, for only two modules present the same address is acceptable
	NRF_WriteRegData(NRF_GetRegCommand(RX_ADDR_P0, WRITE), TX_ADDRESS, TX_ADR_WIDTH);
	NRF_WriteRegData(NRF_GetRegCommand(RX_ADDR_P0, WRITE), TX_ADDRESS, TX_ADR_WIDTH);
	// enable auto ack
	NRF_WriteReg(NRF_GetRegCommand(EN_AA, WRITE), 0x01);
	// enable pipe 0
	NRF_WriteReg(NRF_GetRegCommand(EN_RXADDR, WRITE), 0x01);
	// set payload width to 1 byte
	NRF_WriteReg(NRF_GetRegCommand(RX_PW_P0, WRITE), TX_PLOAD_WIDTH);
	// select RF channel 2
	NRF_WriteReg(NRF_GetRegCommand(RF_CH, WRITE), 2);
	// set 2Mbps bit rate and 0dBm output power level
	NRF_WriteReg(NRF_GetRegCommand(RF_SETUP, WRITE), 0x07);

	NRF_PowerUpRX();
	delay_ms(1);
}
char spiX_readreg(char RegCommand)
{
	char val;
	CSN_H();
	delay_ms(2);
	CSN_L();
	spiX_put(RegCommand);
	spiX_wait();
	spiX_get();
	delay_ms(3);
	spiX_put(0);
	spiX_wait();
	val = spiX_get();
	CSN_H();
	return val;
}


