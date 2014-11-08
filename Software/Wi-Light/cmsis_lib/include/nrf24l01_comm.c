/**
  ******************************************************************************
  * @file    nrf24l01_comm.c
  * @author  M.Targan
  * @version V1.0.0
  * @date    06-October-2014
  * @brief   Set of functions for communication with wireless module
  ******************************************************************************
  */

#include "nrf24l01_comm.h"
#include "stm32f4xx_gpio.h"

/** @brief Global variables */
uint8_t TX_ADDRESS[TX_ADR_WIDTH]  = {0x34,0x43,0x10,0x10,0x01}; // Define default TX address

/** @brief Local functions declarations */
static void NRF_WriteReg(uint8_t RegCommand, uint8_t Value);
static uint8_t NRF_GetRegCommand(uint8_t Reg, uint8_t Operation);
static void NRF_WriteRegData(uint8_t RegCommand, uint8_t* pData, uint8_t DataSize);
static void NRF_ReadRegData(uint8_t RegCommand, uint8_t* pData, uint8_t DataSize);
static uint8_t NRF_ReadReg(uint8_t RegCommand);
static void NRF_PowerUpTX();
static void NRF_PowerDownTX();


#ifdef TEST
static uint8_t NRF_ReadRegRX(uint8_t RegCommand);
static void NRF_WriteRegDataRX(uint8_t Reg, uint8_t* pData, uint8_t DataSize);
static void NRF_WriteRegRX(uint8_t RegCommand, uint8_t Value);
static void NRF_PowerUpRX();
static void NRF_PowerDownRX();
static void NRF_ClearStatusRX();
#endif

/**
 * @brief	None
 *
 * @param	None
 *
 * @return	None
 */
void NRF_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	// configure pin - CE
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Pin = NRF_CE_PIN;

#ifdef TEST
	GPIO_InitStructure.GPIO_Pin = NRF_CE_PIN | NRF_CE_PIN_RX;
	CE_H_RX();
#endif

	//TODO: is CE high needed or not?
	CE_H();
	GPIO_Init(NRF_GPIO_PORT, &GPIO_InitStructure);
}

#ifdef TEST
/**
 * @brief	Read 8bit register from receiver
 * @param	RegCommand				command for reading specific register
 * @return	Byte					byte with register value
 */
static uint8_t NRF_ReadRegRX(uint8_t RegCommand)
{
	uint8_t Byte;

	CSN_L_RX();
	SPI_WriteRead(SPI1, RegCommand);
	Byte = SPI_WriteRead(SPI1, 0);
	CSN_H_RX();
	return Byte;
}
/**
 * @brief	Write register data longer than 8bits
 * @param	RegCommand				command for writing to specific register in receiver
 * @param	pData					pointer to data to be written
 * @param	DataSize				number of bytes to be written
 * @return	None
 */
static void NRF_WriteRegDataRX(uint8_t RegCommand, uint8_t* pData, uint8_t DataSize)
{
	uint8_t ii;

	CSN_L_RX();
	SPI_WriteRead(SPI1, RegCommand);

	for(ii = 0; ii < DataSize; ii++)
	{
		// catching status just for proper data flow, not used
		SPI_WriteRead(SPI1, pData[ii]);
	}
	CSN_H_RX();
}

/**
 * @brief	Read register data longer than 8bits
 * @param	RegCommand				command for reading from specific register in receiver
 * @param	pData					pointer to data to be read
 * @param	DataSize				number of bytes to be read
 * @return	None
 */
static void NRF_ReadRegDataRX(uint8_t RegCommand, uint8_t* pData, uint8_t DataSize)
{
	uint8_t ii;

	CSN_L_RX();
	SPI_WriteRead(SPI1, RegCommand);

	for(ii = 0; ii < DataSize; ii++)
	{
		pData[ii] = SPI_WriteRead(SPI1, 0);
	}
	CSN_H_RX();
}

/**
 * @brief	Write 8bit register in receiver
 * @param	RegCommand				command for writing specific register
 * @param	Value					value to be written to register
 * @return	None
 */
static void NRF_WriteRegRX(uint8_t RegCommand, uint8_t Value)
{
	CSN_L_RX();
	SPI_WriteRead(SPI1, RegCommand);
	SPI_WriteRead(SPI1, Value);
	CSN_H_RX();
}

/**
 * @brief	Power up receiver
 * @param	None
 * @return	None
 */
static void NRF_PowerUpRX(void)
{
	uint8_t RegValue;
	CE_L_RX();
	//can be done by checking every time the real value of register as shown below
	//RegValue = NRF_ReadReg(NRF_GetRegCommand(CONFIG, READ));
	RegValue = CONFIG_DEFAULT | ((FLG_SET << PWR_UP) | (FLG_SET << PRIM_RX));
	NRF_WriteRegRX(NRF_GetRegCommand(CONFIG, WRITE), RegValue);
	CE_H_RX();
}

/**
 * @brief	Flush RX FIFO
 * @param	None
 * @return	None
 */
static void NRF_FlushRX(void)
{
	CSN_L();
	SPI_WriteRead(SPI1, RX_FLUSH);
	CSN_H();
}

/**
 * @brief	Power down receiver
 * @param	None
 * @return	None
 */
static void NRF_PowerDownRX(void)
{
	CE_L_RX();
	NRF_WriteRegRX(NRF_GetRegCommand(CONFIG, WRITE), CONFIG_DEFAULT);
	CE_H_RX();
}

/**
 * @brief	Configure module to RX mode
 * @param	None
 * @return	None
 */
void NRF_ConfigureRX(void)
{
	DelayMs(1);
	// enter standby mode
	CE_L_RX();

	// set receiver address, for only two modules present the same address is acceptable
	NRF_WriteRegDataRX(NRF_GetRegCommand(RX_ADDR_P0, WRITE), TX_ADDRESS, TX_ADR_WIDTH);
	NRF_WriteRegDataRX(NRF_GetRegCommand(RX_ADDR_P0, WRITE), TX_ADDRESS, TX_ADR_WIDTH);
	// enable auto ack
	NRF_WriteRegRX(NRF_GetRegCommand(EN_AA, WRITE), 0x01);
	// enable pipe 0
	NRF_WriteRegRX(NRF_GetRegCommand(EN_RXADDR, WRITE), 0x01);
	// set payload width to 1 byte
	NRF_WriteRegRX(NRF_GetRegCommand(RX_PW_P0, WRITE), TX_PLOAD_WIDTH);
	// select RF channel 2
	NRF_WriteRegRX(NRF_GetRegCommand(RF_CH, WRITE), 2);
	// set 2Mbps bit rate and 0dBm output power level
	NRF_WriteRegRX(NRF_GetRegCommand(RF_SETUP, WRITE), 0x07);

	NRF_PowerUpRX();
	DelayMs(1);

}

/**
 * @brief	Clear status flags in receiver
 * @param	None
 * @return	None
 */
static void NRF_ClearStatusRX()
{
	CSN_L_RX();
	NRF_WriteRegRX(NRF_GetRegCommand(STATUS, WRITE), STATUS_RESET);
	CSN_H_RX();
}

#endif

/**
 * @brief	Get command for register write/read operation
 * @param   Reg					Register map to be configured
 * @param	Operation			Read or Write operation
 * @return	Command byte for r/w operation on given register
 */
static uint8_t NRF_GetRegCommand(uint8_t Reg, uint8_t Operation)
{
	uint8_t OperationMask;

	OperationMask = (Operation ? REGISTER_WRITE : REGISTER_READ);
	return (OperationMask | (REGISTER_MASK & Reg));
}

/**
 * @brief	Write register data longer than 8bits
 * @param	RegCommand				command for writing to specific register in transmitter
 * @param	pData					pointer to data to be written
 * @param	DataSize				number of bytes to be written
 * @return	None
 */
static void NRF_WriteRegData(uint8_t RegCommand, uint8_t* pData, uint8_t DataSize)
{
	uint8_t ii;

	CSN_L();
	SPI_WriteRead(SPI2, RegCommand);

	for(ii = 0; ii < DataSize; ii++)
	{
		SPI_WriteRead(SPI2, pData[ii]);
	}
	CSN_H();
}

/**
 * @brief	Read register data longer than 8bits from transmitter
 * @param	RegCommand				command for reading from specific register in transmitter
 * @param	pData					pointer to data to be read
 * @param	DataSize				number of bytes to be read
 * @return	None
 */
static void NRF_ReadRegData(uint8_t RegCommand, uint8_t* pData, uint8_t DataSize)
{
	uint8_t ii;

	CSN_L();
	SPI_WriteRead(SPI2, RegCommand);

	for(ii = 0; ii < DataSize; ii++)
	{
		pData[ii] = SPI_WriteRead(SPI2, 0);
	}
	CSN_H();
}

/**
 * @brief	Write 8bit register in transmitter
 * @param	RegCommand				command for writing specific register
 * @param	Value					value to be written to register
 * @return	None
 */
static void NRF_WriteReg(uint8_t RegCommand, uint8_t Value)
{
	CSN_L();
	SPI_WriteRead(SPI2, RegCommand);
	SPI_WriteRead(SPI2, Value);
	CSN_H();
}

/**
 * @brief	Read 8bit register from transmitter
 * @param	RegCommand				command for reading specific register
 * @return	Byte					byte with register value
 */
static uint8_t NRF_ReadReg(uint8_t RegCommand)
{
	uint8_t Byte;

	CSN_L();
	SPI_WriteRead(SPI2, RegCommand);
	Byte = SPI_WriteRead(SPI2, 0);
	CSN_H();
	return Byte;
}

/**
 * @brief	Flush TX FIFO
 * @param	None
 * @return	None
 */
static void NRF_FlushTX()
{

	CSN_L();
	SPI_WriteRead(SPI2, TX_FLUSH);
	CSN_H();
}

/**
 * @brief	Power up transmitter
 * @param	None
 * @return	None
 */
static void NRF_PowerUpTX()
{
	uint8_t RegValue;
	CE_L();
	//can be done by checking every time the real value of register as shown below
	//RegValue = NRF_ReadReg(NRF_GetRegCommand(CONFIG, READ));
	//RegValue &= ~(FLG_SET << PRIM_RX);
	RegValue = CONFIG_DEFAULT | (FLG_SET << PWR_UP);
	NRF_WriteReg(NRF_GetRegCommand(CONFIG, WRITE), RegValue);
	CE_H();
}

/**
 * @brief	Clear status flags in transmitter
 * @param	None
 * @return	None
 */
static void NRF_ClearStatus()
{
	CSN_L();
	NRF_WriteReg(NRF_GetRegCommand(STATUS, WRITE), STATUS_RESET);
	CSN_H();
}

/**
 * @brief	Power down transmitter
 * @param	None
 * @return	None
 */
static void NRF_PowerDownTX()
{
	CE_L();
	NRF_WriteReg(NRF_GetRegCommand(CONFIG, WRITE), CONFIG_DEFAULT);
	CE_H();
}

/**
 * @brief	Configure module to TX mode
 * @param	None
 * @return	None
 */
void NRF_ConfigureTX(void)
{
	DelayMs(1);
	// enter standby mode
	CE_L();

	// set TX address
	NRF_WriteRegData(NRF_GetRegCommand(TX_ADDR, WRITE), TX_ADDRESS, TX_ADR_WIDTH);
	// set the same address for receiving auto ack
	NRF_WriteRegData(NRF_GetRegCommand(RX_ADDR_P0, WRITE), TX_ADDRESS, TX_ADR_WIDTH);
	//NRF_WriteRegData(NRF_GetRegCommand(WR_TX_PLOAD, WRITE), BUF, TX_PLOAD_WIDTH); // Writes data to TX payload
	// enable auto ack
	NRF_WriteReg(NRF_GetRegCommand(EN_AA, WRITE), 0x01);
	// enable pipe 0
	NRF_WriteReg(NRF_GetRegCommand(EN_RXADDR, WRITE), 0x01);
	// set retransmission timings, 500us and 10 retries
	NRF_WriteReg(NRF_GetRegCommand(SETUP_RETR, WRITE), 0x1a);
	// select RF channel 2
	NRF_WriteReg(NRF_GetRegCommand(RF_CH, WRITE), 2);
	// set 2Mbps bit rate and 0dBm output power level
	NRF_WriteReg(NRF_GetRegCommand(RF_SETUP, WRITE), 0x07);

	DelayMs(2);
	//NRF_WriteReg(NRF_GetRegCommand(RX_PW_P0, WRITE), TX_PLOAD_WIDTH);
}

/**
 * @brief	Send 8bit data to be transmitted
 * @param	Data					data to be transmitted
 * @return	None
 */
void NRF_Send(uint8_t Data)
{
	uint8_t Status;
	uint8_t DataRX;
	//only 8bit data function has been implemented as sending more than 8bit seems to be unnecessary

	CE_L();

	NRF_FlushTX();
	NRF_ClearStatus();

	NRF_WriteReg(W_TX_PAYLOAD, Data);
	NRF_PowerUpTX();
	DelayMs(1);
	CE_L();

	// wait for a while and check whether message has been sent
	// if not - display a message with error
	// e.g. that connection with a lamp was lost

	DelayMs(20);
	Status = NRF_ReadReg(NRF_GetRegCommand(STATUS, READ));

	if(STATUS_SENT != Status)
	{
		//TODO: insert message to be displayed
	}

#ifdef TEST
	DataRX = NRF_ReadRegRX(R_RX_PAYLOAD);
	NRF_ClearStatusRX();
#endif
}





