#include "stdafx.h"
#include "MsgRecode.h"


CMsgRecode::CMsgRecode()
{
	eventstrs[TEXT("WM_LBUTTONDOWN")] = WM_LBUTTONDOWN;
	eventstrs[TEXT("WM_LBUTTONUP")] = WM_LBUTTONUP;
	eventstrs[TEXT("WM_MOUSEMOVE")] = WM_MOUSEMOVE;
	eventstrs[TEXT("WM_MOUSEWHEEL")] = WM_MOUSEWHEEL;
	eventstrs[TEXT("WM_MOUSEHWHEEL")] = WM_MOUSEHWHEEL;
	eventstrs[TEXT("WM_RBUTTONUP")] = WM_RBUTTONUP;
	eventstrs[TEXT("WM_RBUTTONDOWN")] = WM_RBUTTONDOWN;
	eventstrs[TEXT("WM_KEYUP")] = WM_KEYUP;
	eventstrs[TEXT("WM_KEYDOWN")] = WM_KEYDOWN;
	eventstrs[TEXT("WM_SYSKEYDOWN")] = WM_SYSKEYDOWN;
	eventstrs[TEXT("WM_SYSKEYUP")] = WM_SYSKEYUP;
	eventstrs[TEXT("TIMESPAN")] = TIMESPAN;
}


CMsgRecode::~CMsgRecode()
{
}

BOOL CMsgRecode::LoadRecodeFile(CString strfilename)
{
	CStdioFile recodefile;
	CString tmpstr;
	if (!recodefile.Open(strfilename, CFile::modeRead | CFile::typeText))
	{
		TRACE(_T("Unable to open file\n"));
		AfxMessageBox(TEXT("Unable to open file"));
		return FALSE;
	}

	while (recodefile.ReadString(tmpstr))
	{
		recodelines.push_back(tmpstr);
	}

	return TRUE;
}

void CMsgRecode::RunRecode(CString strfilename)
{
	CStdioFile recodefile;
	CString tmpstr;
	CString eventstr;
	CString paramstr;
	int index;
	POINT mp;
	if (!recodefile.Open(strfilename, CFile::modeRead | CFile::typeText))
	{
		TRACE(_T("Unable to open file\n"));
		AfxMessageBox(TEXT("Unable to open file"));
		return;
	}

	
	while (recodefile.ReadString(tmpstr))
	{
		tmpstr = tmpstr.Trim();
		if (tmpstr.IsEmpty())
		{
			TRACE(_T("file format error\n"));
			//AfxMessageBox(TEXT("file format error"));
			break;
		}

		index = tmpstr.Find(':');
		if(index < 0)
		{
			TRACE(_T("file format error\n"));
			//AfxMessageBox(TEXT("file format error"));
			return;
		}
		eventstr = tmpstr.Left(index);
		paramstr = tmpstr.Right(tmpstr.GetLength()-index-1);
		eventstr = eventstr.Trim();
		paramstr = paramstr.Trim();

		switch (eventstrs[eventstr])
		{
		case WM_LBUTTONDOWN:
		{
			mp = getmousepointbystr(paramstr);
			SetCursorPos(mp.x,mp.y);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		break;
		case WM_LBUTTONUP:
		{
			mp = getmousepointbystr(paramstr);
			SetCursorPos(mp.x, mp.y);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		break;		
		//case WM_MOUSEMOVE:
		//{
		//	SetCursorPos(mp.x, mp.y);
		//}
		//break;
		//case WM_MOUSEWHEEL:
		//{
		//	mp = getmousepointbystr(paramstr);
		//	SetCursorPos(mp.x, mp.y);
		//	mouse_event(MOUSEEVENTF_WHEEL, 0, 0, 0, 0);
		//}
		//break;
		//case WM_MOUSEHWHEEL:
		//{
		//	
		//}
		//break;
		case WM_RBUTTONUP:
		{
			mp = getmousepointbystr(paramstr);
			SetCursorPos(mp.x, mp.y);
			mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
		}
		break;
		case WM_RBUTTONDOWN:
		{
			mp = getmousepointbystr(paramstr);
			SetCursorPos(mp.x, mp.y);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
		}
		break;
		case WM_KEYUP:
		{
			keybd_event(keystr.ToVkeyVal(paramstr), 0, KEYEVENTF_KEYUP, 0);
		}
		break;

		case WM_KEYDOWN:
		{
			keybd_event(keystr.ToVkeyVal(paramstr), 0, 0, 0);
		}
		break;
		//case WM_SYSKEYDOWN:
		//{
		//	
		//}
		//break;
		//case WM_SYSKEYUP:
		//{
		//	
		//}
		//break;
		case TIMESPAN:
		{
			Sleep(StrToInt(paramstr));
		}
		break;
		default:
			break;
		}

	}

}

POINT CMsgRecode::getmousepointbystr(CString mouseparamstr)
{
	POINT p;
	int index;
	CString xstr;
	CString ystr;
	index = mouseparamstr.Find(',');
	xstr = mouseparamstr.Left(index);
	ystr = mouseparamstr.Right(mouseparamstr.GetLength() - index - 1);

    index= xstr.Find('=');
	xstr = xstr.Right(xstr.GetLength() - index - 1);
	xstr = xstr.Trim();

	index = ystr.Find('=');
	ystr = ystr.Right(ystr.GetLength() - index - 1);
	ystr = ystr.Trim();
	p.x = StrToInt(xstr);
	p.y = StrToInt(ystr);

	return p;
}
