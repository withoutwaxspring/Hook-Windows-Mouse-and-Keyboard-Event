
// hookinputDlg.h: 头文件
//

#pragma once
#include "..\..\hookin\hookin\hookin.h"
#include "Timer.h"
#include "KeyString.h"

// ChookinputDlg 对话框
class ChookinputDlg : public CDialogEx
{
// 构造
public:
	ChookinputDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOOKINPUT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	BOOL HitTestRect(RECT rectDes, int xPiont, int yPiont);
public:
	afx_msg void OnBnClickedButton3();

private:
	Chookin* myhooklink;
	CTimer mytimer;
	CKeyString mykeystr;

public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg LRESULT OnSysMouseMessage(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSysKeyboardMessage(WPARAM wParam, LPARAM lParam);
	
	
private:
	CString n_msglog;
   
	BOOL enableRecodeMouseMSG;
	BOOL enableRecodKeybardMSG;
	BOOL preflag;
	

public:
//	afx_msg void OnBnClickedButton4();
//	afx_msg void OnBnClickedButton5();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton6();
private:
	CEdit c_editmsg;
	CButton c_bntrecode;
	CButton c_bntstop;
	CButton c_bntsave;
public:
	afx_msg void OnDestroy();
};
