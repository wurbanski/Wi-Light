#include "TEXT.h"
#include "DIALOG.h"
#include "WM.h"


// Changes state of a light _number_ and displays it in _textbox_
int ToggleLightN(int number, WM_HWIN textbox);
// Change mode of a light _number_
int ToggleLightModeN(int number, WM_HWIN textbox);
// Add new light to the list
// ToDo: define structure
int AddNewLight(int dataStuct);
// Change configuration of a light
int ReconfigureLight(int number, WM_HWIN hWin);
// Remove light from the list
int RemoveLight(int number);
// Set Date and Time
int SetDateTime(WM_HWIN hWin);
