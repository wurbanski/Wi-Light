#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "GUI.h"
#include "LCD.h"

GPIO_InitTypeDef  GPIO_InitStructure;

int main(void)
{
	int xPos, yPos;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CRC, ENABLE);
	//U8 WM_SetCreateFlags(U8 Flags);
    GUI_Init();
    xPos = LCD_GetXSize() / 2;
    yPos = LCD_GetYSize() / 3;
    GUI_SetFont(GUI_FONT_COMIC24B_ASCII);
    GUI_DispStringHCenterAt("Hello world!", xPos, yPos);

    while(1)
    {
    }
}
