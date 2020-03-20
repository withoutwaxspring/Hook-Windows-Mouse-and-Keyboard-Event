
// hookinputDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "hookinput.h"
#include "hookinputDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ChookinputDlg 对话框



ChookinputDlg::ChookinputDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HOOKINPUT_DIALOG, pParent)
	, n_msglog(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ChookinputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, n_msglog);
	DDX_Control(pDX, IDC_EDIT1, c_editmsg);
	DDX_Control(pDX, IDC_BUTTON1, c_bntrecode);
	DDX_Control(pDX, IDC_BUTTON2, c_bntstop);
	DDX_Control(pDX, IDC_BUTTON6, c_bntsave);
}

BEGIN_MESSAGE_MAP(ChookinputDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &ChookinputDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &ChookinputDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ChookinputDlg::OnBnClickedButton2)
	ON_MESSAGE(WM_USER_HOOKMOUSE_MSG,&ChookinputDlg::OnSysMouseMessage)
	ON_MESSAGE(WM_USER_HOOKKEY_MSG, &ChookinputDlg::OnSysKeyboardMessage)
	ON_WM_ACTIVATE()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON6, &ChookinputDlg::OnBnClickedButton6)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// ChookinputDlg 消息处理程序

BOOL ChookinputDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	myhooklink = CreateChookinObj();
	enableRecodeMouseMSG = FALSE;
	enableRecodKeybardMSG = FALSE;
	mytimer.reset();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void ChookinputDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void ChookinputDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR ChookinputDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//
//   函数: HitTestRect(RECT rectDes, int xPiont,int yPiont)
//
//   目标: 测试坐标点是否在矩形内
//
//   注释:
//
// 
BOOL ChookinputDlg::HitTestRect(RECT rectDes, int xPiont, int yPiont)
{
	return ((xPiont >= rectDes.left) & (xPiont <= rectDes.right) & (yPiont >= rectDes.top) & (yPiont <= rectDes.bottom));

}



void ChookinputDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


//启动键盘鼠标HOOK
void ChookinputDlg::OnBnClickedButton1()
{
	BOOL bResult = FALSE;

	bResult = myhooklink->startMousehook(this->GetSafeHwnd());
	if (!bResult)
	{
		MessageBox(TEXT("HOOK失败"));
		return;
	}

	bResult = myhooklink->startKeyboardhook(this->GetSafeHwnd());

	if (!bResult)
	{
		MessageBox(TEXT("HOOK失败"));
		return;
	}
	c_bntrecode.EnableWindow(FALSE);
	c_bntsave.EnableWindow(FALSE);
	c_editmsg.EnableWindow(FALSE);
	mytimer.start();
	// TODO: 在此添加控件通知处理程序代码
}

//关闭键盘鼠标HOOK
void ChookinputDlg::OnBnClickedButton2()
{
	BOOL bResult = FALSE;
	bResult = myhooklink->stopMousehook();
	if (!bResult)
	{
		MessageBox(TEXT("UNHOOK失败"));
		return;
	}

	bResult = myhooklink->stopKeyboardhook();
	if (!bResult)
	{
		MessageBox(TEXT("UNHOOK失败"));
		return;
	}
	c_bntrecode.EnableWindow(TRUE);
	c_bntsave.EnableWindow(TRUE);
	c_editmsg.EnableWindow(TRUE);
	// TODO: 在此添加控件通知处理程序代码
}

LRESULT ChookinputDlg::OnSysMouseMessage(WPARAM wParam, LPARAM lParam)
{
	LPMOUSEHOOKSTRUCT mhookstruct = (LPMOUSEHOOKSTRUCT)lParam;

	//if (this->IsTopParentActive())
	//{
	//	//(CWnd::GetForegroundWindow()->GetSafeHwnd()) == this->GetSafeHwnd()
	//	RECT winrect;
	//	POINT mp = mhookstruct->pt;
	//	this->GetWindowRect(&winrect);
	//	//this->GetWindowRgn();
	//	if (HitTestRect(winrect, mp.x, mp.y))
	//	{
	//		enableRecodeMouseMSG = FALSE;
	//		enableRecodKeybardMSG = FALSE;
	//	}
	//	else
	//	{
	//		enableRecodeMouseMSG = TRUE;
	//		enableRecodKeybardMSG = TRUE;
	//	}
	//}

	RECT winrect;
	POINT mp = mhookstruct->pt;
	this->GetWindowRect(&winrect);
	if (!HitTestRect(winrect, mp.x, mp.y))
	{
		enableRecodeMouseMSG = TRUE;
		enableRecodKeybardMSG = TRUE;
	}

	if (!enableRecodeMouseMSG)
	{
		return 0;
	}

	
	switch (wParam)
	{
	case WM_LBUTTONDOWN:
	{

		UpdateData(TRUE);
		n_msglog.Format(TEXT("%sTIMESPAN:%d\r\n"), n_msglog, mytimer.get_timespan());
		mytimer.reset();
		mytimer.start();
		n_msglog.Format(TEXT("%sWM_LBUTTONDOWN:X=%d,Y=%d \r\n"), n_msglog, mhookstruct->pt.x, mhookstruct->pt.y);
		UpdateData(FALSE);
		c_editmsg.LineScroll(c_editmsg.GetLineCount());
	}
	break;
		case  WM_LBUTTONUP:
		{
			UpdateData(TRUE);
			n_msglog.Format(TEXT("%sTIMESPAN:%d\r\n"), n_msglog, mytimer.get_timespan());
			mytimer.reset();
			mytimer.start();
			n_msglog.Format(TEXT("%sWM_LBUTTONUP:X=%d,Y=%d \r\n"), n_msglog, mhookstruct->pt.x, mhookstruct->pt.y);
			UpdateData(FALSE);
			c_editmsg.LineScroll(c_editmsg.GetLineCount());
		}
		break;
		//case WM_MOUSEMOVE:
		//{
		//	UpdateData(TRUE);
		//	n_msglog.Format(TEXT("%sTIMESPAN:%d\r\n"), n_msglog, mytimer.get_timespan());
		//	mytimer.reset();
		//	mytimer.start();
		//	n_msglog.Format(TEXT("%WM_MOUSEMOVE:X=%d,Y=%d \r\n"), n_msglog, mhookstruct->pt.x, mhookstruct->pt.y);
		//	UpdateData(FALSE);
		//}
		//break;
		case WM_MOUSEWHEEL:
		{
			UpdateData(TRUE);
			n_msglog.Format(TEXT("%sTIMESPAN:%d\r\n"), n_msglog, mytimer.get_timespan());
			mytimer.reset();
			mytimer.start();
			n_msglog.Format(TEXT("%sWM_MOUSEWHEEL:X=%d,Y=%d \r\n"), n_msglog, mhookstruct->pt.x, mhookstruct->pt.y);
			UpdateData(FALSE);
			c_editmsg.LineScroll(c_editmsg.GetLineCount());
		}
		break;
		case  WM_MOUSEHWHEEL:
		{
			UpdateData(TRUE);
			n_msglog.Format(TEXT("%sTIMESPAN:%d\r\n"), n_msglog, mytimer.get_timespan());
			mytimer.reset();
			mytimer.start();
			n_msglog.Format(TEXT("%sWM_MOUSEHWHEEL:X=%d,Y=%d \r\n"), n_msglog, mhookstruct->pt.x, mhookstruct->pt.y);
			UpdateData(FALSE);
			c_editmsg.LineScroll(c_editmsg.GetLineCount());
		}
		break;
		case WM_RBUTTONDOWN:
		{
			UpdateData(TRUE);
			n_msglog.Format(TEXT("%sTIMESPAN:%d\r\n"), n_msglog, mytimer.get_timespan());
			mytimer.reset();
			mytimer.start();
			n_msglog.Format(TEXT("%sWM_RBUTTONDOWN:X=%d,Y=%d \r\n"), n_msglog, mhookstruct->pt.x, mhookstruct->pt.y);
			UpdateData(FALSE);
			c_editmsg.LineScroll(c_editmsg.GetLineCount());
		}
		break;
		case WM_RBUTTONUP:
		{
			UpdateData(TRUE);
			n_msglog.Format(TEXT("%sTIMESPAN:%d\r\n"), n_msglog, mytimer.get_timespan());
			mytimer.reset();
			mytimer.start();
			n_msglog.Format(TEXT("%sWM_RBUTTONUP:X=%d,Y=%d \r\n"), n_msglog, mhookstruct->pt.x, mhookstruct->pt.y);
			UpdateData(FALSE);
			c_editmsg.LineScroll(c_editmsg.GetLineCount());
		}
	break;
	default:
		break;
	}

	return 0;
}

      

LRESULT ChookinputDlg::OnSysKeyboardMessage(WPARAM wParam, LPARAM lParam)
{
	if (!enableRecodKeybardMSG)
	{
		return 0;
	}

	LPKBDLLHOOKSTRUCT pKeyboardHook = (LPKBDLLHOOKSTRUCT)lParam;
	switch (wParam)
	{
		case WM_KEYDOWN:
		{
			UpdateData(TRUE);
			n_msglog.Format(TEXT("%sTIMESPAN:%d\r\n"), n_msglog, mytimer.get_timespan());
			mytimer.reset();
			mytimer.start();
			GetKeyState(pKeyboardHook->vkCode);
			n_msglog.Format(TEXT("%sWM_KEYDOWN:%s\r\n"), n_msglog, mykeystr.ToVkeyName(pKeyboardHook->vkCode));
			UpdateData(FALSE);
			c_editmsg.LineScroll(c_editmsg.GetLineCount());
		}
		break;
		case  WM_KEYUP:
		{
			//WORD ckey;
		//BYTE bKeyState[256];
		//GetKeyboardState(bKeyState);
		//ToAscii(pKeyboardHook->vkCode, pKeyboardHook->scanCode, bKeyState, &ckey, 0);
			GetKeyState(pKeyboardHook->vkCode);
			UpdateData(TRUE);
			n_msglog.Format(TEXT("%sTIMESPAN:%d\r\n"), n_msglog, mytimer.get_timespan());
			mytimer.reset();
			mytimer.start();
		
			n_msglog.Format(TEXT("%sWM_KEYUP:%s\r\n"), n_msglog,mykeystr.ToVkeyName(pKeyboardHook->vkCode));
			UpdateData(FALSE);
			c_editmsg.LineScroll(c_editmsg.GetLineCount());
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
		break;
	    default:
		break;
	}

	return 0;
}


//void ChookinputDlg::OnBnClickedButton4()
//{
//	BOOL bResult = FALSE;
//
//	bResult=myhooklink->startKeyboardhook(this->GetSafeHwnd());
//
//	if (!bResult)
//	{
//		MessageBox(TEXT("HOOK失败"));
//		return;
//	}
//
//	mytimer.start();
//	// TODO: 在此添加控件通知处理程序代码
//}


//void ChookinputDlg::OnBnClickedButton5()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	BOOL bResult = FALSE;
//	bResult = myhooklink->stopKeyboardhook();
//	if (!bResult)
//	{
//		MessageBox(TEXT("UNHOOK失败"));
//	}
//}


void ChookinputDlg::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	switch (nState)
	{
	case WA_ACTIVE:
	case WA_CLICKACTIVE:
	{
		enableRecodeMouseMSG = FALSE;
		enableRecodKeybardMSG = FALSE;
	}
	break;

	case WA_INACTIVE:
	{
		enableRecodeMouseMSG = TRUE;
		enableRecodKeybardMSG = TRUE;
		preflag = TRUE;
	}
	break;
	default:
		break;
	}

	CDialogEx::OnActivate(nState, pWndOther, bMinimized);

	// TODO: 在此处添加消息处理程序代码
}





void ChookinputDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	enableRecodeMouseMSG = FALSE;
	enableRecodKeybardMSG = FALSE;
	CDialogEx::OnMouseMove(nFlags, point);
}


void ChookinputDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CFileDialog savefiledlg(FALSE,TEXT("txt"),TEXT("recode.txt"));
	//savefiledlg.DoModal();
	
	CString filenamestr;

	if (savefiledlg.DoModal() == IDOK)
	{
	    //filenamestr = savefiledlg.GetFileName();
		filenamestr = savefiledlg.GetPathName();
		CStdioFile savefile;
		if(!savefile.Open(filenamestr, CFile::modeReadWrite | CFile::modeCreate| CFile::typeText))
		{
				TRACE(_T("Unable to open file\n"));
				AfxMessageBox(TEXT("创建文件失败！"));
				return;
		}
		
		CString formatforfilestr = n_msglog;
		formatforfilestr.Remove('\r');

		savefile.WriteString(formatforfilestr);
		savefile.Flush();

		//CStdioFile f2(stdout);
		//try
		//{
		//	CStdioFile f3(pFileName,
		//		CFile::modeCreate | CFile::modeWrite | CFile::typeText);
		//}
		//catch (CFileException* pe)
		//{
		//	TRACE(_T("File could not be opened, cause = %d\n"),
		//		pe->m_cause);
		//	pe->Delete();
		//}
		//AfxMessageBox(filenamestr);
		//CFileStatus filestatus;
		//if (CFile::GetStatus(filenamestr, filestatus))
		//{
		//	if (AfxMessageBox(TEXT("文件存在是否覆盖？"), MB_YESNO) != IDYES)
		//	{
		//		return;
		//	}
		//}

		//CFile savefile(filenamestr, CFile::modeWrite | CFile::modeCreate);
		//if (savefile.m_hFile == CFile::hFileNull)
		//{
		//	AfxMessageBox(TEXT("创建文件失败！"));
		//	return ;
		//}

		//UINT nlength = n_msglog.GetLength();
		//savefile.Write(n_msglog.GetBuffer(),nlength);
		//savefile.Flush();
		//n_msglog.ReleaseBuffer();
	}

	
}


void ChookinputDlg::OnDestroy()
{
	DestroyChookinObj(myhooklink);
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
}
