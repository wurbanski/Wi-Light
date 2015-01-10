/*
 * spi_via_usi_driver.h
 *
 * Created: 2015-01-06 13:12:58
 *  Author: Joanna
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay_basic.h>
#ifndef SPI_VIA_USI_DRIVER_H_
#define SPI_VIA_USI_DRIVER_H_

#define F_CPU 1000000UL
/* USI port and pin definitions.
 */
#define USI_OUT_REG	PORTB	//!< USI port output register.
#define USI_IN_REG	PINB	//!< USI port input register.
#define USI_DIR_REG	DDRB	//!< USI port direction register.
#define USI_CLOCK_PIN	PB2	//!< USI clock I/O pin.
#define USI_DATAIN_PIN	PB0	//!< USI data input pin.
#define USI_DATAOUT_PIN	PB1	//!< USI data output pin.
#define USI_CSN_PIN PB4
#define USI_CE_PIN PB3



/*  Speed configuration:
 *  Bits per second = CPUSPEED / PRESCALER / (COMPAREVALUE+1) / 2.
 *  Maximum = CPUSPEED / 64.
 */
#define TC0_PRESCALER_VALUE 256	//!< Must be 1, 8, 64, 256 or 1024.
#define TC0_COMPARE_VALUE   1	//!< Must be 0 to 255. Minimum 31 with prescaler CLK/1.


#define RX_DR 0x06

/*  Prescaler value converted to bit settings.
 */
#if TC0_PRESCALER_VALUE == 1
	#define TC0_PS_SETTING (1<<CS00)
#elif TC0_PRESCALER_VALUE == 8
	#define TC0_PS_SETTING (1<<CS01)
#elif TC0_PRESCALER_VALUE == 64
	#define TC0_PS_SETTING (1<<CS01)|(1<<CS00)
#elif TC0_PRESCALER_VALUE == 256
	#define TC0_PS_SETTING (1<<CS02)
#elif TC0_PRESCALER_VALUE == 1024
	#define TC0_PS_SETTING (1<<CS02)|(1<<CS00)
#else
	#error Invalid T/C0 prescaler setting.
#endif


#define TX_ADR_WIDTH    5   // 5 bytes TX/RX address width
#define TX_PLOAD_WIDTH  1  // 20 bytes TX/RX payload

#define CONFIG          0x00  // 'Config' register address
#define EN_AA           0x01  // 'Enable Auto Acknowledgment' register address
#define EN_RXADDR       0x02  // 'Enabled RX addresses' register address
#define SETUP_AW        0x03  // 'Setup address width' register address
#define SETUP_RETR      0x04  // 'Setup Auto. Retrans' register address
#define RF_CH           0x05  // 'RF channel' register address
#define RF_SETUP        0x06  // 'RF setup' register address
#define STATUS          0x07  // 'Status' register address
#define OBSERVE_TX      0x08  // 'Observe TX' register address
#define CD              0x09  // 'Carrier Detect' register address
#define RX_ADDR_P0      0x0A  // 'RX address pipe0' register address
#define RX_ADDR_P1      0x0B  // 'RX address pipe1' register address
#define RX_ADDR_P2      0x0C  // 'RX address pipe2' register address
#define RX_ADDR_P3      0x0D  // 'RX address pipe3' register address
#define RX_ADDR_P4      0x0E  // 'RX address pipe4' register address
#define RX_ADDR_P5      0x0F  // 'RX address pipe5' register address
#define TX_ADDR         0x10  // 'TX address' register address
#define RX_PW_P0        0x11  // 'RX payload width, pipe0' register address
#define RX_PW_P1        0x12  // 'RX payload width, pipe1' register address
#define RX_PW_P2        0x13  // 'RX payload width, pipe2' register address
#define RX_PW_P3        0x14  // 'RX payload width, pipe3' register address
#define RX_PW_P4        0x15  // 'RX payload width, pipe4' register address
#define RX_PW_P5        0x16  // 'RX payload width, pipe5' register address
#define FIFO_STATUS     0x17  // 'FIFO Status Register' register address
#define FLG_SET				0x01
#define FLG_CLRD			0x00
#define PWR_UP			0x01
#define PRIM_RX			0x00
#define TX_DR			0x06
#define TX_DS			0x05
#define MAX_RT			0x04
#define EN_CRC			0x03
#define CRCO			0x02
#define CONFIG_DEFAULT	((FLG_SET << EN_CRC) | (FLG_CLRD << CRCO))
#define STATUS_SENT 	(FLG_SET << TX_DS)

#define REGISTER_MASK 			0b00011111
#define REGISTER_WRITE			0b00100000
#define REGISTER_READ			0b00000000
#define R_RX_PAYLOAD     		0x61  // Define RX payload register address
#define W_TX_PAYLOAD		    0xA0  // Define TX payload register address
#define TX_FLUSH        		0xE1  // Define flush TX register command
#define RX_FLUSH        		0xE2  // Define flush RX register command
#define REUSE_TX_PL     		0xE3  // Define reuse TX payload register command
#define NOP             		0xFF  // Define No Operation, might be used to read status register
#define R_RX_PL_WID				0x60
#define STATUS_RESET			0x7E

#define WRITE					0x01
#define READ					0x00


void delay_ms(uint16_t ms);
void LED_ON_f();
void LED_OFF();
void CSN_L();
void CSN_H();
void CE_L();
void CE_H();
void spiX_initmaster( char spi_mode );
void spiX_init_slavemodule();
void spiX_free_slavemodule();
void spiX_initslave( char spi_mode );
char spiX_put( unsigned char val );
unsigned char spiX_get();
void spiX_wait();
uint8_t NRF_GetRegCommand(uint8_t Reg, uint8_t Operation);
void NRF_WriteRegData(uint8_t RegCommand, uint8_t* pData, uint8_t DataSize);
void NRF_WriteReg(uint8_t RegCommand, uint8_t Value);
void NRF_PowerUpRX(void);
void NRF_configure_RX();
char spiX_readreg(char RegCommand);

#endif /* SPI_VIA_USI_DRIVER_H_ */