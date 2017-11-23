// Win32Test1.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Win32Test1.h"
#include "ContainerContents.h"

WIN32TEST1_API unsigned long WINAPI GetContentIIDCount(void)
{
	return 2UL;
}

WIN32TEST1_API unsigned long WINAPI GetContentIIDs(_In_ unsigned long celt, _In_ _Out_ IID **riids)
{
	*riids[0] = __uuidof(Win32Test1::Win32Package1);
	
	return 1UL;
}

WIN32TEST1_API HRESULT WINAPI CreateInstance(_In_ IID iid, HCONTENT *phContent)
{
	if (iid == __uuidof(Win32Test1::Win32Package1))
	{
		*phContent = (HCONTENT)(new Win32Test1::Win32Package1());
		return S_OK;
	}
	else
	{
		phContent = NULL;
		return E_NOINTERFACE;
	}
}

WIN32TEST1_API void WINAPI Release(HCONTENT hContent)
{
	((Win32Test1::Win32Package1*)hContent)->~Win32Package1();
}
