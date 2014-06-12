#include "gui_comm.h"

int ToggleLightN(int number, WM_HWIN textbox) {
	//ToDo: get element _number_ from the list
	//ToDo: communicate
	//ToDo: toggle state
	TEXT_SetText(textbox, "Status: Off");
	return 0;
}

int ToggleLightModeN(int number, WM_HWIN textbox) {
	//ToDo: get element _number from the list
	//ToDo: Communicate
	//ToDo: toggle mode
	TEXT_SetText(textbox, "Mode: Manual");
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
