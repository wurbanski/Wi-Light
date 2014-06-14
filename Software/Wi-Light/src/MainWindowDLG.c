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

#include "DIALOG.h"
#include "MENU.h"

/*********************************************************************
 *
 *       Defines
 *
 **********************************************************************
 */
#define ID_WINDOW_0     (GUI_ID_USER + 0x00)
#define ID_IMAGE_0     (GUI_ID_USER + 0x03)
#define ID_MENU_MAIN     (GUI_ID_USER + 0x05)
#define ID_TEXT_DATE     (GUI_ID_USER + 0x07)
#define ID_TEXT_TIME     (GUI_ID_USER + 0x08)
#define ID_MENU_LIGHTS_CONFIGURE	(GUI_ID_USER + 0x09)
#define ID_MENU_CONFIGURATION_DATETIME	(GUI_ID_USER + 0x0A)
#define ID_MENU_HELP_ABOUT	(GUI_ID_USER + 0x0B)

#define ID_IMAGE_0_IMAGE_0     0x00


/*********************************************************************
 *
 *       Static data
 *
 **********************************************************************
 */
/*********************************************************************
 *
 *       _acImage_0, "BMP", ID_IMAGE_0_IMAGE_0
 */
static U8 _acImage_0[463] = { 0x42, 0x4D, 0xCE, 0x01, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x32, 0x00,
		0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x90, 0x01, 0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x12, 0x0B,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
		0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xC0, 0x00, 0xC2, 0x10, 0x84, 0x21, 0x08, 0x42, 0x40, 0x00, 0xA1, 0x08,
		0x42, 0x10, 0x84, 0x21, 0x40, 0x00, 0x90, 0x84, 0x21, 0x08, 0x42, 0x10,
		0xC0, 0x00, 0x88, 0x42, 0x10, 0x84, 0x21, 0x08, 0x40, 0x00, 0x84, 0x21,
		0x08, 0x42, 0x10, 0x84, 0x40, 0x00, 0xC2, 0x10, 0x84, 0x21, 0x08, 0x42,
		0x40, 0x00, 0xA1, 0x08, 0x42, 0x10, 0x84, 0x21, 0x40, 0x00, 0x90, 0x84,
		0x21, 0x08, 0x42, 0x10, 0xC0, 0x00, 0x88, 0x42, 0x10, 0x84, 0x21, 0x08,
		0x40, 0x00, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x40, 0x00, 0xC2, 0x10,
		0x84, 0x21, 0x08, 0x42, 0x40, 0x00, 0xA1, 0x08, 0x42, 0x10, 0x84, 0x21,
		0x40, 0x00, 0x90, 0x84, 0x21, 0x08, 0x42, 0x10, 0xC0, 0x00, 0x88, 0x42,
		0x10, 0x84, 0x21, 0x08, 0x40, 0x00, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84,
		0x40, 0x00, 0xC2, 0x10, 0x84, 0x21, 0x08, 0x42, 0x40, 0x00, 0xA1, 0x08,
		0x42, 0x10, 0x84, 0x21, 0x40, 0x00, 0x90, 0x84, 0x21, 0x08, 0x42, 0x10,
		0xC0, 0x00, 0x88, 0x42, 0x10, 0x84, 0x21, 0x08, 0x40, 0x00, 0x84, 0x21,
		0x08, 0x42, 0x10, 0x84, 0x40, 0x00, 0xC2, 0x10, 0x84, 0x21, 0x08, 0x42,
		0x40, 0x00, 0xA1, 0x08, 0x42, 0x10, 0x84, 0x21, 0x40, 0x00, 0x90, 0x84,
		0x21, 0x08, 0x42, 0x10, 0xC0, 0x00, 0x88, 0x42, 0x10, 0x84, 0x21, 0x08,
		0x40, 0x00, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x40, 0x00, 0xC2, 0x10,
		0x84, 0x21, 0x08, 0x42, 0x40, 0x00, 0xA1, 0x08, 0x42, 0x10, 0x84, 0x21,
		0x40, 0x00, 0x90, 0x84, 0x21, 0x08, 0x42, 0x10, 0xC0, 0x00, 0x88, 0x42,
		0x10, 0x84, 0x21, 0x08, 0x40, 0x00, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84,
		0x40, 0x00, 0xC2, 0x10, 0x84, 0x21, 0x08, 0x42, 0x40, 0x00, 0xA1, 0x08,
		0x42, 0x10, 0x84, 0x21, 0x40, 0x00, 0x90, 0x84, 0x21, 0x08, 0x42, 0x10,
		0xC0, 0x00, 0x88, 0x42, 0x10, 0x84, 0x21, 0x08, 0x40, 0x00, 0x84, 0x21,
		0x08, 0x42, 0x10, 0x84, 0x40, 0x00, 0xC2, 0x10, 0x84, 0x21, 0x08, 0x42,
		0x40, 0x00, 0xA1, 0x08, 0x42, 0x10, 0x84, 0x21, 0x40, 0x00, 0x90, 0x84,
		0x21, 0x08, 0x42, 0x10, 0xC0, 0x00, 0x88, 0x42, 0x10, 0x84, 0x21, 0x08,
		0x40, 0x00, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x40, 0x00, 0xC2, 0x10,
		0x84, 0x21, 0x08, 0x42, 0x40, 0x00, 0xA1, 0x08, 0x42, 0x10, 0x84, 0x21,
		0x40, 0x00, 0x90, 0x84, 0x21, 0x08, 0x42, 0x10, 0xC0, 0x00, 0x88, 0x42,
		0x10, 0x84, 0x21, 0x08, 0x40, 0x00, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84,
		0x40, 0x00, 0xC2, 0x10, 0x84, 0x21, 0x08, 0x42, 0x40, 0x00, 0xA1, 0x08,
		0x42, 0x10, 0x84, 0x21, 0x40, 0x00, 0x90, 0x84, 0x21, 0x08, 0x42, 0x10,
		0xC0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, };


/*********************************************************************
 *
 *       _aDialogCreate
 */
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = { {
		WINDOW_CreateIndirect, "MainWindow", ID_WINDOW_0, 0, 0, 320, 240, 0,
		0x0, 0 }, { IMAGE_CreateIndirect, "Image", ID_IMAGE_0, 133, 93, 50, 51,
		0, 0, 0 }, { MENU_CreateIndirect, "Menu", ID_MENU_MAIN, 0, 0, 320, 19, 0,
		0x0, 0 }, { TEXT_CreateIndirect, "Text", ID_TEXT_DATE, 6, 220, 69, 16, 0,
		0x64, 0 }, { TEXT_CreateIndirect, "Text", ID_TEXT_TIME, 234, 220, 80, 20,
		0, 0x64, 0 },
		};

/*********************************************************************
 *
 *       Static code
 *
 **********************************************************************
 */

/*********************************************************************
*
*       _AddMenuItem
*/
static void _AddMenuItem(MENU_Handle hMenu, MENU_Handle hSubmenu, const char * pText, U16 Id, U16 Flags) {
  MENU_ITEM_DATA Item;

  Item.pText    = pText;
  Item.hSubmenu = hSubmenu;
  Item.Flags    = Flags;
  Item.Id       = Id;
  MENU_AddItem(hMenu, &Item);
}


/*********************************************************************
 *
 *       _GetImageById
 */
static const void * _GetImageById(U32 Id, U32 * pSize) {
	switch (Id) {
	case ID_IMAGE_0_IMAGE_0:
		*pSize = sizeof(_acImage_0);
		return (const void *) _acImage_0;
	}
	return NULL;
}

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
 *
 *       _cbDialog
 */
static void _cbDialog(WM_MESSAGE * pMsg) {
	MENU_ITEM_DATA ItemData;
	const void * pData;
	WM_HWIN hItem,hSubmenu,hDateTime,hManLights;
	MENU_MSG_DATA* pMenuData;
	U32 FileSize;
	int NCode;
	int Id;

	switch (pMsg->MsgId) {
	case WM_INIT_DIALOG:
		//
		// Initialization of 'MainWindow'
		//
		hItem = pMsg->hWin;
		WINDOW_SetBkColor(hItem, 0x00000000);
		//
		// Initialization of 'Image'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_0);
		pData = _GetImageById(ID_IMAGE_0_IMAGE_0, &FileSize);
		IMAGE_SetBMP(hItem, pData, FileSize);
		//
		// Initialization of 'Menu'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_MENU_MAIN);

		// Create "Lights" menu
		hSubmenu = MENU_CreateEx(0, 0, 0, 0, WM_UNATTACHED, 0, MENU_CF_VERTICAL, 0);
		_AddMenuItem(hSubmenu, 0, "Manage Lights...", ID_MENU_LIGHTS_CONFIGURE, 0);
		_AddMenuItem(hItem, hSubmenu, "Lights", 0, 0);

		// Create "Configuration" menu
		hSubmenu = MENU_CreateEx(0, 0, 0, 0, WM_UNATTACHED, 0, MENU_CF_VERTICAL, 0);
		_AddMenuItem(hSubmenu, 0, "Date/Time...", ID_MENU_CONFIGURATION_DATETIME, 0);
		_AddMenuItem(hItem, hSubmenu, "Configuration", 0, 0);

		// Create "About" menu
		hSubmenu = MENU_CreateEx(0, 0, 0, 0, WM_UNATTACHED, 0, MENU_CF_VERTICAL, 0);
		_AddMenuItem(hSubmenu, 0, "About...", ID_MENU_HELP_ABOUT, 0);
		_AddMenuItem(hItem, hSubmenu, "Help", 0, 0);

		//
		// Initialization of 'Text'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_DATE);
		TEXT_SetTextColor(hItem, 0x00EFEFEF);
		TEXT_SetFont(hItem, GUI_FONT_16B_ASCII);
		TEXT_SetText(hItem, "08/06/2014");
		//
		// Initialization of 'Text'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_TIME);
		TEXT_SetTextColor(hItem, 0x00FFFFFF);
		TEXT_SetFont(hItem, GUI_FONT_16B_1);
		TEXT_SetText(hItem, "23:09");
		TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_TOP);
		break;
	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch (Id) {
		}
		break;
	case WM_MENU:
		pMenuData = (MENU_MSG_DATA*) pMsg->Data.p;
		switch (pMenuData->MsgType) {
		case MENU_ON_ITEMSELECT:
			switch (pMenuData->ItemId) {
			case ID_MENU_CONFIGURATION_DATETIME:
				hDateTime = CreateDateTime();
				break;
			case ID_MENU_LIGHTS_CONFIGURE:
				hManLights = CreateManageLights();
				break;
			case ID_MENU_HELP_ABOUT:
				GUI_MessageBox("Wi-Light v. 0.1a", "About", GUI_MESSAGEBOX_CF_MOVEABLE);
				break;
			default:
				break;
			}
		}
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
 *       CreateMainWindow
 */WM_HWIN CreateMainWindow(void);
WM_HWIN CreateMainWindow(void) {
	WM_HWIN hWin;

	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate),
			_cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

/*************************** End of file ****************************/
