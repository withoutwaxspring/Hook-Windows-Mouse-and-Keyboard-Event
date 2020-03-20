#include "stdafx.h"
#include "KeyString.h"


CKeyString::CKeyString()
{
	DWORD i;
	//int j;
	CString tmpstr;

	keylist[VK_LBUTTON] = TEXT("VK_LBUTTON");
	keylist[VK_RBUTTON] = TEXT("VK_RBUTTON");
	keylist[VK_CANCEL] = TEXT("VK_CANCEL");
	keylist[VK_MBUTTON] = TEXT("VK_MBUTTON");
	keylist[VK_XBUTTON1] = TEXT("VK_XBUTTON1");
	keylist[VK_XBUTTON2] = TEXT("VK_XBUTTON2");
	//0x07    Undefined
	tmpstr.Format(TEXT("UNKONWKEY%d"), 0x07);
	keylist[0x07] = tmpstr;

	keylist[VK_BACK] = TEXT("VK_BACK");
	keylist[VK_TAB] = TEXT("VK_TAB");

	//0x0A - 0B   Reserved
	tmpstr.Format(TEXT("UNKONWKEY%d"), 0x0A);
	keylist[0x0A] = tmpstr;
	tmpstr.Format(TEXT("UNKONWKEY%d"), 0x0B);
	keylist[0x0B] = tmpstr;

	keylist[VK_CLEAR] = TEXT("VK_CLEAR");
	keylist[VK_RETURN] = TEXT("VK_RETURN");

	//0x0E - 0F    Undefined
	tmpstr.Format(TEXT("UNKONWKEY%d"), 0x0E);
	keylist[0x0E] = tmpstr;
	tmpstr.Format(TEXT("UNKONWKEY%d"), 0x0F);
	keylist[0x0F] = tmpstr;

	keylist[VK_SHIFT] = TEXT("VK_SHIFT");
	keylist[VK_CONTROL] = TEXT("VK_CONTROL");
	keylist[VK_MENU] = TEXT("VK_MENU");
	keylist[VK_PAUSE] = TEXT("VK_PAUSE");
	keylist[VK_CAPITAL] = TEXT("VK_CAPITAL");
	keylist[VK_KANA] = TEXT("VK_KANA");
	//keylist[VK_HANGUEL] = TEXT("VK_HANGUEL");
	//keylist[VK_HANGUL] = TEXT("VK_HANGUL");

	//keylist[VK_IME_ON] = TEXT("VK_IME_ON");
	tmpstr.Format(TEXT("UNKONWKEY%d"), 0x16);
	keylist[0x16] = tmpstr;

	keylist[VK_JUNJA] = TEXT("VK_JUNJA");
	keylist[VK_FINAL] = TEXT("VK_FINAL");
	keylist[VK_HANJA] = TEXT("VK_HANJA");
	//keylist[VK_KANJI] = TEXT("VK_KANJI");
	//keylist[VK_IME_OFF] = TEXT("VK_IME_OFF");
	tmpstr.Format(TEXT("UNKONWKEY%d"), 0x1A);
	keylist[0x1A] = tmpstr;


	keylist[VK_ESCAPE] = TEXT("VK_ESCAPE");
	keylist[VK_CONVERT] = TEXT("VK_CONVERT");
	keylist[VK_NONCONVERT] = TEXT("VK_NONCONVERT");
	keylist[VK_ACCEPT] = TEXT("VK_ACCEPT");
	keylist[VK_MODECHANGE] = TEXT("VK_MODECHANGE");
	keylist[VK_SPACE] = TEXT("VK_SPACE");
	keylist[VK_PRIOR] = TEXT("VK_PRIOR");
	keylist[VK_NEXT] = TEXT("VK_NEXT");
	keylist[VK_END] = TEXT("VK_END");
	keylist[VK_HOME] = TEXT("VK_HOME");
	keylist[VK_LEFT] = TEXT("VK_LEFT");
	keylist[VK_UP] = TEXT("VK_UP");
	keylist[VK_RIGHT] = TEXT("VK_RIGHT");
	keylist[VK_DOWN] = TEXT("VK_DOWN");
	keylist[VK_SELECT] = TEXT("VK_SELECT");
	keylist[VK_PRINT] = TEXT("VK_PRINT");
	keylist[VK_EXECUTE] = TEXT("VK_EXECUTE");
	keylist[VK_SNAPSHOT] = TEXT("VK_SNAPSHOT");
	keylist[VK_INSERT] = TEXT("VK_INSERT");
	keylist[VK_DELETE] = TEXT("VK_DELETE");
	keylist[VK_HELP] = TEXT("VK_HELP");

	//Number
	for (i = 0x30; i < 0x40; i++)
	{
		tmpstr.Format(TEXT("%d"), i- 0x30);
		keylist[i] = tmpstr;
	}

	//0x3A - 40  Undefined 
	for (i = 0x3A; i < 0x41; i++)
	{
		tmpstr.Format(TEXT("UNKONWKEY%d"), i);
		keylist[i] = tmpstr;
	}

	//LETTER
	for (i = 0x41; i < 0x5B; i++)
	{
		
		tmpstr.Format(TEXT("%c"), i);
		keylist[i] = tmpstr;
	}

	keylist[VK_LWIN] = TEXT("VK_LWIN");
	keylist[VK_RWIN] = TEXT("VK_RWIN");
	keylist[VK_APPS] = TEXT("VK_APPS");

	//0x5E  Reserved
	tmpstr.Format(TEXT("UNKONWKEY%d"), 0x5E);
	keylist[0x5E] = tmpstr;

	keylist[VK_SLEEP] = TEXT("VK_SLEEP");

	for (i = 0x60; i < 0x6A; i++)
	{
		tmpstr.Format(TEXT("VK_NUMPAD%d"), i - 0x60);
		keylist[i] = tmpstr;
	}

	keylist[VK_MULTIPLY] = TEXT("VK_MULTIPLY");
	keylist[VK_ADD] = TEXT("VK_ADD");
	keylist[VK_SEPARATOR] = TEXT("VK_SEPARATOR");
	keylist[VK_SUBTRACT] = TEXT("VK_SUBTRACT");
	keylist[VK_DECIMAL] = TEXT("VK_DECIMAL");
	keylist[VK_DIVIDE] = TEXT("VK_DIVIDE");

	for (i = 0x70; i < 0x88; i++)
	{
		tmpstr.Format(TEXT("VK_F%d"), i - 0x6F);
		keylist[i] = tmpstr;
	}
	//0x88 - 8F  Unassigned
	for (i = 0x88; i < 0x90; i++)
	{
		tmpstr.Format(TEXT("UNKONWKEY%d"), i);
		keylist[i] = tmpstr;
	}

	keylist[VK_NUMLOCK] = TEXT("VK_NUMLOCK");
	keylist[VK_SCROLL] = TEXT("VK_SCROLL");
	//0x92 - 96  OEM specific
    //0x97 - 9F  Unassigned
	for (i = 0x92; i < 0xA0; i++)
	{
		tmpstr.Format(TEXT("UNKONWKEY%d"), i);
		keylist[i] = tmpstr;
	}

	keylist[VK_LSHIFT] = TEXT("VK_LSHIFT");
	keylist[VK_RSHIFT] = TEXT("VK_RSHIFT");
	keylist[VK_LCONTROL] = TEXT("VK_LCONTROL");
	keylist[VK_RCONTROL] = TEXT("VK_RCONTROL");
	keylist[VK_LMENU] = TEXT("VK_LMENU");
	keylist[VK_RMENU] = TEXT("VK_RMENU");
	keylist[VK_BROWSER_BACK] = TEXT("VK_BROWSER_BACK");
	keylist[VK_BROWSER_FORWARD] = TEXT("VK_BROWSER_FORWARD");
	keylist[VK_BROWSER_REFRESH] = TEXT("VK_BROWSER_REFRESH");
	keylist[VK_BROWSER_STOP] = TEXT("VK_BROWSER_STOP");
	keylist[VK_BROWSER_SEARCH] = TEXT("VK_BROWSER_SEARCH");
	keylist[VK_BROWSER_FAVORITES] = TEXT("VK_BROWSER_FAVORITES");
	keylist[VK_BROWSER_HOME] = TEXT("VK_BROWSER_HOME");
	keylist[VK_VOLUME_MUTE] = TEXT("VK_VOLUME_MUTE");
	keylist[VK_VOLUME_DOWN] = TEXT("VK_VOLUME_DOWN");
	keylist[VK_VOLUME_UP] = TEXT("VK_VOLUME_UP");
	keylist[VK_MEDIA_NEXT_TRACK] = TEXT("VK_MEDIA_NEXT_TRACK");
	keylist[VK_MEDIA_PREV_TRACK] = TEXT("VK_MEDIA_PREV_TRACK");
	keylist[VK_MEDIA_STOP] = TEXT("VK_MEDIA_STOP");
	keylist[VK_MEDIA_PLAY_PAUSE] = TEXT("VK_MEDIA_PLAY_PAUSE");
	keylist[VK_LAUNCH_MAIL] = TEXT("VK_LAUNCH_MAIL");
	keylist[VK_LAUNCH_MEDIA_SELECT] = TEXT("VK_LAUNCH_MEDIA_SELECT");
	keylist[VK_LAUNCH_APP1] = TEXT("VK_LAUNCH_APP1");
	keylist[VK_LAUNCH_APP2] = TEXT("VK_LAUNCH_APP2");

	//0xB8 - B9  Reserved
	tmpstr.Format(TEXT("UNKONWKEY%d"), 0xB8);
	keylist[0xB8] = tmpstr;
	tmpstr.Format(TEXT("UNKONWKEY%d"), 0xB9);
	keylist[0xB9] = tmpstr;


	keylist[VK_OEM_1] = TEXT("VK_OEM_1");
	keylist[VK_OEM_PLUS] = TEXT("VK_OEM_PLUS");
	keylist[VK_OEM_COMMA] = TEXT("VK_OEM_COMMA");
	keylist[VK_OEM_MINUS] = TEXT("VK_OEM_MINUS");
	keylist[VK_OEM_PERIOD] = TEXT("VK_OEM_PERIOD");
	keylist[VK_OEM_2] = TEXT("VK_OEM_2");
	keylist[VK_OEM_3] = TEXT("VK_OEM_3");
	
	//0xC1 - D7 Reserved
	//0xD8 - DA  Unassigned
	for (i = 0xC1; i < 0xDB; i++)
	{
		tmpstr.Format(TEXT("UNKONWKEY%d"), i);
		keylist[i] = tmpstr;
	}

	keylist[VK_OEM_4] = TEXT("VK_OEM_4");
	keylist[VK_OEM_5] = TEXT("VK_OEM_5");
	keylist[VK_OEM_6] = TEXT("VK_OEM_6");
	keylist[VK_OEM_7] = TEXT("VK_OEM_7");
	keylist[VK_OEM_8] = TEXT("VK_OEM_8");
	//0xE0  Reserved
	//0xE1  OEM specific
	tmpstr.Format(TEXT("UNKONWKEY%d"), 0xE0);
	keylist[0xE0] = tmpstr;
	tmpstr.Format(TEXT("UNKONWKEY%d"), 0xE1);
	keylist[0xE1] = tmpstr;

	keylist[VK_OEM_102] = TEXT("VK_OEM_102");
	//0xE3 - E4 OEM specific
	tmpstr.Format(TEXT("UNKONWKEY%d"), 0xE3);
	keylist[0xE3] = tmpstr;
	tmpstr.Format(TEXT("UNKONWKEY%d"), 0xE4);
	keylist[0xE4] = tmpstr;

	keylist[VK_PROCESSKEY] = TEXT("VK_PROCESSKEY");
	//0xE6  OEM specific
	tmpstr.Format(TEXT("UNKONWKEY%d"), 0xE6);
	keylist[0xE6] = tmpstr;

	keylist[VK_PACKET] = TEXT("VK_PACKET");

	//0xE8    Unassigned
	//0xE9 - F5   OEM specific
	for (i = 0xE8; i < 0xF6; i++)
	{
		tmpstr.Format(TEXT("UNKONWKEY%d"), i);
		keylist[i] = tmpstr;
	}

	keylist[VK_ATTN] = TEXT("VK_ATTN");
	keylist[VK_CRSEL] = TEXT("VK_CRSEL");
	keylist[VK_EXSEL] = TEXT("VK_EXSEL");
	keylist[VK_EREOF] = TEXT("VK_EREOF");
	keylist[VK_PLAY] = TEXT("VK_PLAY");
	keylist[VK_ZOOM] = TEXT("VK_ZOOM");
	keylist[VK_NONAME] = TEXT("VK_NONAME"); //Reserved
	keylist[VK_PA1] = TEXT("VK_PA1");
	keylist[VK_OEM_CLEAR] = TEXT("VK_OEM_CLEAR");

}


CKeyString::~CKeyString()
{
}

DWORD CKeyString::ToVkeyVal(CString keyname)
{
	CString resulst;
	for (DWORD i = 0; i < 255; i++)
	{
		if (keylist[i] == keyname)
		{
			return i;
		}
	}
	return 0;
}

CString CKeyString::ToVkeyName(DWORD vkeyval)
{
	return keylist[vkeyval];
}
