#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "global_defs.h"
#include "spi_comm.h"
#include "GUI.h"

#ifndef NRF24L01_H
#define NRF24L01_H

#define status_t	uint8_t // TODO: move it to some global header

#define CE_H()   GPIO_SetBits(GPIOD, GPIO_Pin_2)
#define CE_L()   GPIO_ResetBits(GPIOD, GPIO_Pin_2)

#define CSN_H()  GPIO_SetBits(GPIOB, GPIO_Pin_12)
#define CSN_L()  GPIO_ResetBits(GPIOB, GPIO_Pin_12)


#ifdef TEST

#define CE_H_RX()   GPIO_SetBits(GPIOD, GPIO_Pin_3)
#define CE_L_RX()   GPIO_ResetBits(GPIOD, GPIO_Pin_3)

#define CSN_H_RX()  GPIO_SetBits(GPIOA, GPIO_Pin_4)
#define CSN_L_RX()  GPIO_ResetBits(GPIOA, GPIO_Pin_4)

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
#define STATUS_RESET			0x7E

#define WRITE					0x01
#define READ					0x00

#define NRF_GPIO_PORT			GPIOD
#define NRF_CE_PIN				GPIO_Pin_2
#define NRF_GPIO_CLK			RCC_AHB1Periph_GPIOD

#define DelayMs					GUI_Delay

#ifdef TEST
#define NRF_CE_PIN_RX			GPIO_Pin_3
#endif

/**
 * @brief	None
 * @param	None
 * @return	None
 */
void NRF_Init(void);

void NRF_ConfigureTX(void);
#ifdef TEST
void NRF_ConfigureRX(void);
#endif
void NRF_Send(uint8_t Data);

#endif
