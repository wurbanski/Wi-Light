#include "stm32f4xx_rcc.h"
#include "stm32f4xx.h"
#include "stm32f4xx_spi.h"
#ifndef SPI_COMM_H
#define SPI_COMM_H

// TODO: remove this definition when testing is finished
//#define TEST

/** @brief SPI number definition */
#define SPI_PORT					SPI2

/** @brief SPI peripheral clock definitions */
#define SPI_PORT_CLOCK				RCC_APB1Periph_SPI2

/** @brief Clock enabling functions */
#define SPI_PORT_CLOCK_INIT			RCC_APB1PeriphClockCmd
#define SPI_PERIPH_CLOCK_INIT		RCC_AHB1PeriphClockCmd

/** @brief SCK, MISO and MOSI alternate function pins definition */
#define SPI_SCK_SOURCE           	GPIO_PinSource13
#define SPI_MOSI_SOURCE          	GPIO_PinSource15
#define SPI_MISO_SOURCE          	GPIO_PinSource14

/** @brief SCK, MISO and MOSI port pins definition */
#define SPI_SCK_PIN					GPIO_Pin_13
#define SPI_MOSI_PIN				GPIO_Pin_15
#define SPI_MISO_PIN				GPIO_Pin_14
#define SPI_CS_PIN					GPIO_Pin_12

/** @brief SPI IO port definitions */
#define SPI_GPIO_PORT				GPIOB

/** @brief GPIO peripheral clock definitions */
#define SPI_GPIO_CLK				RCC_AHB1Periph_GPIOB

/** @brief GPIO pins alternate function selection */
#define SPI_SCK_AF               	GPIO_AF_SPI2
#define SPI_MOSI_AF             	GPIO_AF_SPI2
#define SPI_MISO_AF             	GPIO_AF_SPI2

#ifdef TEST
#define SPI_PORT_RX					SPI1
#define SPI_PORT_CLOCK_RX			RCC_APB2Periph_SPI1
#define SPI_PORT_CLOCK_INIT_RX		RCC_APB2PeriphClockCmd
#define SPI_SCK_SOURCE_RX           GPIO_PinSource5
#define SPI_MOSI_SOURCE_RX			GPIO_PinSource7
#define SPI_MISO_SOURCE_RX			GPIO_PinSource6
#define SPI_SCK_PIN_RX				GPIO_Pin_5
#define SPI_MOSI_PIN_RX				GPIO_Pin_7
#define SPI_MISO_PIN_RX				GPIO_Pin_6
#define SPI_CS_PIN_RX			    GPIO_Pin_4
#define SPI_GPIO_PORT_RX			GPIOA
#define SPI_GPIO_CLK_RX				RCC_AHB1Periph_GPIOA
#define SPI_SCK_AF_RX				GPIO_AF_SPI1
#define SPI_MOSI_AF_RX             	GPIO_AF_SPI1
#endif

void SPI_InitConf();
uint8_t SPI_WriteRead(SPI_TypeDef* SPIx, uint8_t Byte);
void SPI_WriteData(SPI_TypeDef* SPIx, uint8_t* pData, uint8_t DataSize);

#endif
