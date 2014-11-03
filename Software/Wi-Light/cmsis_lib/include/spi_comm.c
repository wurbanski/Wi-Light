/**
  ******************************************************************************
  * @file    spi_comm.c
  * @author  M.Targan
  * @version V1.0.0
  * @date    12-August-2014
  * @brief   API for SPI usage adjusted for the Wi-Light project
  ******************************************************************************
  */

#include "spi_comm.h"
#include "stm32f4xx_spi.h"
#include "stm32f4xx_gpio.h"
#include "nrf24l01_comm.h"

/**
 * @brief	None
 * @param	None
 * @return	None
 */
void SPI_InitConf()
{

	SPI_InitTypeDef SPI_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	// enable the SPI peripheral clock (should it be APB2 or APB1?)
	SPI_PORT_CLOCK_INIT(SPI_PORT_CLOCK, ENABLE);
	// enable the peripheral GPIO port clocks
	SPI_PERIPH_CLOCK_INIT(SPI_GPIO_CLK, ENABLE);
	// Connect SPI pins to alternate functions pins
	GPIO_PinAFConfig(SPI_GPIO_PORT, SPI_SCK_SOURCE, SPI_SCK_AF);
	GPIO_PinAFConfig(SPI_GPIO_PORT, SPI_MOSI_SOURCE, SPI_MOSI_AF);
	GPIO_PinAFConfig(SPI_GPIO_PORT, SPI_MISO_SOURCE, SPI_MISO_AF);
	// configure pins - SCK, MISO, MOSI
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Pin = SPI_SCK_PIN | SPI_MOSI_PIN | SPI_MISO_PIN;

	GPIO_Init(SPI_GPIO_PORT, &GPIO_InitStructure);

	// configure pins - CS
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Pin = SPI_CS_PIN;

	CSN_H();
	GPIO_Init(SPI_GPIO_PORT, &GPIO_InitStructure);

	// now we can set up the SPI peripheral
	// Assume the target is write only and we look after the chip select ourselves
	// SPI clock rate will be system frequency/4/prescaler
	// so here we will go for 72/4/8 = 2.25MHz
	SPI_I2S_DeInit(SPI_PORT); // is this really needed?
	SPI_StructInit(&SPI_InitStructure);
	// after init there are set default values, some of them are to be changed
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4; //check if it shouldn't be 4

	SPI_Init(SPI_PORT, &SPI_InitStructure);
	// Enable the SPI port
	SPI2->CR2 |= SPI_CR2_SSOE;
	SPI_Cmd(SPI_PORT, ENABLE);

#ifdef TEST

	// enable the SPI peripheral clock
	// TODO: check if SPI1 should be used - high speed apb
	SPI_PORT_CLOCK_INIT_RX(SPI_PORT_CLOCK_RX, ENABLE);
	// enable the peripheral GPIO port clocks
	SPI_PERIPH_CLOCK_INIT(SPI_GPIO_CLK_RX, ENABLE);
	// Connect SPI pins to alternate functions pins
	GPIO_PinAFConfig(SPI_GPIO_PORT_RX, SPI_SCK_SOURCE_RX, SPI_SCK_AF);
	GPIO_PinAFConfig(SPI_GPIO_PORT_RX, SPI_MOSI_SOURCE_RX, SPI_MOSI_AF);
	GPIO_PinAFConfig(SPI_GPIO_PORT_RX, SPI_MISO_SOURCE_RX, SPI_MISO_AF);
	// configure pins - SCK, MISO, MOSI
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Pin = SPI_SCK_PIN_RX | SPI_MOSI_PIN_RX | SPI_MISO_PIN_RX;

	GPIO_Init(SPI_GPIO_PORT_RX, &GPIO_InitStructure);

	// configure pins - CS
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Pin = SPI_CS_PIN_RX;

	CSN_H();
	GPIO_Init(SPI_GPIO_PORT_RX, &GPIO_InitStructure);

	// now we can set up the SPI peripheral
	// Assume the target is write only and we look after the chip select ourselves
	// SPI clock rate will be system frequency/4/prescaler
	// so here we will go for 72/4/8 = 2.25MHz
	SPI_I2S_DeInit(SPI_PORT_RX); // is this really needed?
	SPI_StructInit(&SPI_InitStructure);
	// after init there are set default values, some of them are to be changed
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4; //check if it shouldn't be 4

	SPI_Init(SPI_PORT_RX, &SPI_InitStructure);

	// Enable the SPI port
	SPI1->CR2 |= SPI_CR2_SSOE;
	SPI_Cmd(SPI_PORT_RX, ENABLE);

#endif
}

/**
 * @brief	None
 * @param	None
 * @return	None
 */
uint8_t SPI_WriteRead(SPI_TypeDef* SPIx, uint8_t Byte)
{
	/* Loop while DR register in not empty */
	while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET);
	/* Send byte through the SPIx peripheral */
	SPI_I2S_SendData(SPIx, Byte);
	/* Wait to receive a byte */
	while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_RXNE) == RESET);
	/* Return the byte read from the SPI bus */
	return SPI_I2S_ReceiveData(SPIx);
}



