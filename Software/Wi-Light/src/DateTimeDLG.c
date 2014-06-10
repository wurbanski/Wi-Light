/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.22                          *
*        Compiled Jul  4 2013, 15:16:01                              *
*        (c) 2013 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0            (GUI_ID_USER + 0x1A)
#define ID_SPINBOX_0            (GUI_ID_USER + 0x1B)
#define ID_SPINBOX_1            (GUI_ID_USER + 0x1C)
#define ID_SPINBOX_2            (GUI_ID_USER + 0x1D)
#define ID_TEXT_0            (GUI_ID_USER + 0x1E)
#define ID_TEXT_1            (GUI_ID_USER + 0x1F)
#define ID_TEXT_2            (GUI_ID_USER + 0x20)
#define ID_SPINBOX_3            (GUI_ID_USER + 0x21)
#define ID_SPINBOX_4            (GUI_ID_USER + 0x22)
#define ID_TEXT_3            (GUI_ID_USER + 0x23)
#define ID_TEXT_4            (GUI_ID_USER + 0x24)
#define ID_BUTTON_0            (GUI_ID_USER + 0x25)


// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "DateTime", ID_FRAMEWIN_0, 56, 45, 208, 150, 0, 0x0, 0 },
  { SPINBOX_CreateIndirect, "Day", ID_SPINBOX_0, 27, 40, 37, 20, 0, 0x0, 0 },
  { SPINBOX_CreateIndirect, "Month", ID_SPINBOX_1, 73, 40, 37, 20, 0, 0x0, 0 },
  { SPINBOX_CreateIndirect, "Year", ID_SPINBOX_2, 119, 40, 49, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "DayText", ID_TEXT_0, 27, 20, 31, 18, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "MonthText", ID_TEXT_1, 70, 20, 31, 18, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "YearText", ID_TEXT_2, 119, 20, 31, 18, 0, 0x64, 0 },
  { SPINBOX_CreateIndirect, "Hour", ID_SPINBOX_3, 27, 90, 37, 20, 0, 0x0, 0 },
  { SPINBOX_CreateIndirect, "Minutes", ID_SPINBOX_4, 73, 90, 37, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "HourText", ID_TEXT_3, 27, 70, 37, 18, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "MinutesText", ID_TEXT_4, 74, 70, 41, 18, 0, 0x64, 0 },
  { BUTTON_CreateIndirect, "OKButton", ID_BUTTON_0, 125, 83, 52, 27, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'DayText'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetText(hItem, "Day");
    TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
    //
    // Initialization of 'MonthText'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
    TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
    TEXT_SetTextColor(hItem, 0x00000000);
    TEXT_SetText(hItem, "Month");
    //
    // Initialization of 'YearText'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    TEXT_SetText(hItem, "Year");
    TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
    //
    // Initialization of 'HourText'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
    TEXT_SetText(hItem, "Hour");
    TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
    //
    // Initialization of 'MinutesText'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
    TEXT_SetText(hItem, "Minutes");
    TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
    //
    // Initialization of 'OKButton'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetText(hItem, "OK");
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    WM_MakeModal(pMsg->hWin);
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_SPINBOX_0: // Notifications sent by 'Day'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_SPINBOX_1: // Notifications sent by 'Month'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_SPINBOX_2: // Notifications sent by 'Year'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_SPINBOX_3: // Notifications sent by 'Hour'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_SPINBOX_4: // Notifications sent by 'Minutes'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_0: // Notifications sent by 'OKButton'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        GUI_EndDialog(pMsg->hWin, 0);
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateDateTime
*/
WM_HWIN CreateDateTime(void);
WM_HWIN CreateDateTime(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/