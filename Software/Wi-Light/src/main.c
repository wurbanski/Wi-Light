/**
 ******************************************************************************
 * @file    main.c
 * @author  MCD Application Team
 * @version V1.1.2
 * @date    28-January-2014
 * @brief   This file provides main program functions
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
 *
 * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *        http://www.st.com/software_license_agreement_liberty_v2
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "bsp.h"
#include "spi_comm.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint8_t GUI_Initialized = 0;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/**
 * @brief  Main program.
 * @param  None
 * @retval None
 */
int main(void) {

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

	/* Initilize the BSP layer */
	BSP_Init();

	/* Activate the use of memory device feature */
	WM_SetCreateFlags(WM_CF_MEMDEV);

	/* Init the STemWin GUI Library */
	GUI_Init();

	GUI_Initialized = 1;

	/* Initialize and configure SPI */
	SPI_InitConf();

	/* Start Demo */
//  GUIDEMO_Main();
	MainTask();
}

/**
 * @brief  BSP_Background.
 * @param  None
 * @retval None
 */
void BSP_Background(void) {
	static uint32_t POINTER_ticks = 0;

	if (POINTER_ticks++ > 50) {
		POINTER_ticks = 0;
		/* Capture input event and updade cursor */
		if (GUI_Initialized == 1) {
			BSP_Pointer_Update();
		}
	}
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *   where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{}
}
#endif

/*********************************************************************
 *
 *       MainTask
 */
void MainTask(void) {
	GUI_HWIN hWinMain;
	GUI_Init();
	GUI_CURSOR_Show();
	WM_SetDesktopColor(GUI_BLACK);
#if GUI_SUPPORT_MEMDEV
	WM_SetCreateFlags(WM_CF_MEMDEV);
#endif
	// TODO: Create Parent window
	hWinMain = CreateMainWindow();
	while (1) {
		GUI_Delay(10);
	}
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
