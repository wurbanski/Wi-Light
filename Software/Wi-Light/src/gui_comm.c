#include "gui_comm.h"
#include "GUI.h"
#include "nrf24l01_comm.h"

extern unsigned char LED_on;

struct _LIGHT_DATA
{
	unsigned int Address;
	unsigned int State	  : 1,
				 Reserved : 31;
} LIGHT_DATA;

int ToggleLightN(int number, WM_HWIN textbox) {
	//ToDo: get element _number_ from the list
	if (LED_on == 0) {
		TEXT_SetText(textbox, "Status: On");
		NRF_Send(0xCA);
		LED_on = 1;
	} else {
		TEXT_SetText(textbox, "Status: Off");
		NRF_Send(0xAC);
		LED_on = 0;
	}
	return 0;
}

int TriggerSOS(int number, WM_HWIN textbox) {
	//ToDo: get element _number from the list
	int i=0;
	if (LED_on == 0) {

			TEXT_SetText(textbox, "Mode: SOS");
			LED_on = 1;
			for (i=0; i<3; i++) { // pip, pip, pip
				NRF_Send(0xCA);
				GUI_Delay(500);
				NRF_Send(0xAC);
				GUI_Delay(250);
			}
			for (i=0; i<3; i++) { // piiip, piiip, piiip
				NRF_Send(0xCA);
				GUI_Delay(500);
				NRF_Send(0xAC);
				GUI_Delay(250);
			}
			for (i=0; i<3; i++) { // pip, pip, pip
				NRF_Send(0xCA);
				GUI_Delay(500);
				NRF_Send(0xAC);
				GUI_Delay(250);
			}
			LED_on = 0;
	}
	return 0;
}
int AddNewLight(int dataStuct) {
	//ToDo: Everything
	return 0;
}

int ReconfigureLight(int number, WM_HWIN hWin) {
	//ToDo: Get Values from controls in dialog
	//ToDo: Update fields in structure for _number_
	return 0;
}

int RemoveLight(int number) {
	//ToDo: Prompt with yes/no window
	//ToDo: Remove element
	return 0;
}

int SetDateTime(WM_HWIN hWin) {
	//ToDo: Get values from controls
	//ToDo: Set System time and Date
}
