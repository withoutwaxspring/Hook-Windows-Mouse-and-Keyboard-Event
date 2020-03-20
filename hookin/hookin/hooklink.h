#pragma once

#include "hookin.h"

//
//本类在开始HOOK之后会发送给指定窗口自定义事件如下：
//带有鼠标信息的事件ID UINT gl_MOUSEHOOk_MSG = WM_USER + 1005;
//带有键盘信息的事件ID UINT gl_KEYHOOK_MSG = WM_USER + 1006;
//
//

class Chooklink :public Chookin
{
public:
	Chooklink();
	~Chooklink();
	//
	//开始HOOK鼠标
	//参数hwnd接收HOOK事件的窗口
	//
	virtual BOOL startMousehook(HWND hwnd);

	//停止HOOK鼠标
	virtual BOOL stopMousehook();

	//
	//开始HOOK键盘；
	//参数hwnd接收HOOK事件的窗口
	//
	virtual BOOL startKeyboardhook(HWND hwnd);

	//停止HOOK键盘
	virtual BOOL stopKeyboardhook();
	virtual void Rerealse();


};