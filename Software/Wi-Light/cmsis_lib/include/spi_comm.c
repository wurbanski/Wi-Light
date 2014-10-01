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
	RCC_AHB1PeriphClockCmd(SPI_SCK_GPIO_CLK | SPI_MOSI_GPIO_CLK, ENABLE);
	// Connect SPI pins to alternate functions pins
	GPIO_PinAFConfig(SPI_SCK_GPIO_PORT, SPI_SCK_SOURCE, SPI_SCK_AF);
	GPIO_PinAFConfig(SPI_MOSI_GPIO_PORT, SPI_MOSI_SOURCE, SPI_MOSI_AF);
	// now configure the pins themselves
	// they are all going to be fast push-pull outputs
	// but the SPI pins use the alternate function
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Pin = SPI_SCK_PIN;

	// GPIO init
	GPIO_Init(SPI_SCK_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = SPI_MOSI_PIN;
	GPIO_Init(SPI_MOSI_GPIO_PORT, &GPIO_InitStructure);

	// now we can set up the SPI peripheral
	// Assume the target is write only and we look after the chip select ourselves
	// SPI clock rate will be system frequency/4/prescaler
	// so here we will go for 72/4/8 = 2.25MHz
	SPI_I2S_DeInit(SPI_PORT); // is this really needed?
	SPI_StructInit(&SPI_InitStructure);
	// after init there are set default values, some of them are to be changed
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_Direction = SPI_Direction_1Line_Tx;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8; //check if it shouldn't be 4

	SPI_Init(SPI_PORT, &SPI_InitStructure);
	// Enable the SPI port
	SPI_Cmd(SPI_PORT, ENABLE);
}

