// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "hookin.h"
#include "hooklink.h"

extern HINSTANCE glhInst;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
	{
		glhInst = hModule;
	}	
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

HOOKIN_API Chookin* APIENTRY CreateChookinObj()
{
	return new Chooklink;
}

HOOKIN_API void APIENTRY DestroyChookinObj(Chookin* pChookin)
{
	pChookin->Rerealse();
}
