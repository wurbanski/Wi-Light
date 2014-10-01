#include "stm32f4xx_rcc.h"

#define SPI_PORT                  SPI2
#define SPI_PORT_CLOCK            RCC_APB1Periph_SPI2
#define SPI_PORT_CLOCK_INIT       RCC_APB1PeriphClockCmd

#define SPI_SCK_PIN              GPIO_Pin_13
#define SPI_SCK_GPIO_PORT        GPIOB
#define SPI_SCK_GPIO_CLK         RCC_AHB1Periph_GPIOB
#define SPI_SCK_SOURCE           GPIO_PinSource13
#define SPI_SCK_AF               GPIO_AF_SPI2

#define SPI_MOSI_PIN             GPIO_Pin_15
#define SPI_MOSI_GPIO_PORT       GPIOB
#define SPI_MOSI_GPIO_CLK        RCC_AHB1Periph_GPIOB
#define SPI_MOSI_SOURCE          GPIO_PinSource15
#define SPI_MOSI_AF              GPIO_AF_SPI2

void SPI_InitConf();
