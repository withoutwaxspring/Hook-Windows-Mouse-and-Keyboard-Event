// hooklink.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "hooklink.h"

#pragma data_seg("sharedata")
// 源窗口句柄
HWND glhSourceMouseWnd = NULL;
HWND glhSourceKeyboardWnd = NULL;
//本DLL实例句柄
HINSTANCE glhInst = NULL;
//保存鼠标钩子句柄
HHOOK glhMouseHook = NULL;
//保存键盘钩子句柄
HHOOK glhKeyboardHook = NULL;

//发送给窗口的自定义事件ID
UINT gl_MOUSEHOOk_MSG = WM_USER + 1005;
UINT gl_KEYHOOK_MSG = WM_USER + 1006;
#pragma data_seg()

#pragma comment(linker,"/section:sharedata,rws")
//#pragma comment(lib, "//*.lib")

void showerr(const wchar_t *m) {
	wchar_t message[255];
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, GetLastError()
		, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), message, 255, 0);
	MessageBox(NULL, message, m, MB_OK);
}

LRESULT WINAPI LowLevelMouseProc(int nCode, WPARAM wparam, LPARAM lparam)
{
	LPMOUSEHOOKSTRUCT pMouseHook = (LPMOUSEHOOKSTRUCT)lparam;
	if (nCode >= 0)
	{
		SendMessage(glhSourceMouseWnd, gl_MOUSEHOOk_MSG, wparam, lparam);
		//switch (wparam)
		//{
		//	case WM_LBUTTONDOWN:
		//	{
		//		SendMessage(glhSourceMouseWnd, gl_MOUSEHOOk_MSG, wparam, lparam);
		//	}
		//	break;
		//	case  WM_LBUTTONUP:
		//	{
		//		SendMessage(glhSourceMouseWnd, gl_MOUSEHOOk_MSG, wparam, lparam);
		//	}
		//	break;
		//	case WM_MOUSEMOVE:
		//	{
		//		SendMessage(glhSourceMouseWnd, gl_MOUSEHOOk_MSG, wparam, lparam);
		//	}
		//	break;
		//	case WM_MOUSEWHEEL:
		//	{
		//		SendMessage(glhSourceMouseWnd, gl_MOUSEHOOk_MSG, wparam, lparam);
		//	}
		//	break;
		//	case  WM_MOUSEHWHEEL:
		//	{
		//		SendMessage(glhSourceMouseWnd, gl_MOUSEHOOk_MSG, wparam, lparam);
		//	}
		//	break;
		//	case WM_RBUTTONDOWN:
		//	{
		//		SendMessage(glhSourceMouseWnd, gl_MOUSEHOOk_MSG, wparam, lparam);
		//	}
		//	break;
		//	case WM_RBUTTONUP:
		//	{
		//		SendMessage(glhSourceMouseWnd, gl_MOUSEHOOk_MSG, wparam, lparam);
		//	}
		//	break;
		//	break;
		//    default:
		//	break;
		//}
	}

	return CallNextHookEx(glhMouseHook, nCode, wparam, lparam);
}

LRESULT WINAPI LowLevelKeyboardProc(int nCode, WPARAM wparam, LPARAM lparam)
{

	if (nCode >= 0)
	{
		LPKBDLLHOOKSTRUCT pKeyboardHook = (LPKBDLLHOOKSTRUCT)lparam;
		SendMessage(glhSourceKeyboardWnd, gl_KEYHOOK_MSG, wparam, lparam);
		//switch (wparam)
		//{
		//	case WM_KEYDOWN:
		//	{
		//		SendMessage(glhSourceKeyboardWnd, gl_KEYHOOK_MSG, wparam, lparam);
		//	}
		//	break;
		//	case  WM_KEYUP:
		//	{
		//		SendMessage(glhSourceKeyboardWnd, gl_KEYHOOK_MSG, wparam, lparam);
		//	}
		//	break;
		//	case WM_SYSKEYDOWN:
		//	{
		//		SendMessage(glhSourceKeyboardWnd, gl_KEYHOOK_MSG, wparam, lparam);
		//	}
		//	break;
		//	case WM_SYSKEYUP:
		//	{
		//		SendMessage(glhSourceKeyboardWnd, gl_KEYHOOK_MSG, wparam, lparam);
		//	}
		//	break;
		//    default:
		//	break;
		//}
	}

	return CallNextHookEx(glhKeyboardHook, nCode, wparam, lparam);
}

Chooklink::Chooklink()
{
}

Chooklink::~Chooklink()
{
	stopMousehook();
	stopKeyboardhook();
}

BOOL Chooklink::startMousehook(HWND hwnd)
{
	BOOL bResult = FALSE;

	if (glhMouseHook != NULL)
		return bResult;

	glhMouseHook = SetWindowsHookEx(WH_MOUSE_LL, LowLevelMouseProc, glhInst, 0);
	if (glhMouseHook)
	{
		bResult = TRUE;
		glhSourceMouseWnd = hwnd;
	}
	else
	{
		showerr(TEXT("HookMouse失败"));
		return bResult;
	}

	return bResult;
}

BOOL Chooklink::startKeyboardhook(HWND hwnd)
{
	BOOL bResult = FALSE;

	if (glhKeyboardHook != NULL)
		return bResult;

	glhKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, glhInst, 0);
	if (glhKeyboardHook)
	{
		bResult = TRUE;
		glhSourceKeyboardWnd = hwnd;
	}
	else
	{
		showerr(TEXT("HookKeyboard失败"));
		return bResult;
	}

	return bResult;
}

BOOL Chooklink::stopMousehook()
{
	BOOL bResult = FALSE;
	if (glhMouseHook)
	{
		bResult = UnhookWindowsHookEx(glhMouseHook);
		if (bResult)
		{
			glhMouseHook = NULL;
			HWND glhSourceMouseWnd = NULL;
		}
		else
		{
			showerr(TEXT("UnhookMouse失败"));
			return bResult;
		}
	}

	return bResult;
}

BOOL Chooklink::stopKeyboardhook()
{
	BOOL bResult = FALSE;
	if (glhKeyboardHook)
	{
		bResult = UnhookWindowsHookEx(glhKeyboardHook);
		if (bResult)
		{
			glhKeyboardHook = NULL;
			glhSourceKeyboardWnd = NULL;

		}
		else
		{
			showerr(TEXT("UnhookKeyboard失败"));
			return bResult;
		}
	}

	return bResult;

}

void Chooklink::Rerealse()
{
	stopMousehook();
	stopKeyboardhook();
	delete this;
}
