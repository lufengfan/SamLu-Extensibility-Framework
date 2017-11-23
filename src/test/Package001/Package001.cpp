// Package001.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Package001.h"

#include "packs.h"

EXTERN_C
{

PACKAGE001_API ULONG WINAPI GetContentIIDCount()
{
	return 1UL;
}

PACKAGE001_API ULONG WINAPI GetContentIIDs(_In_ ULONG celt, _In_ _Out_ GUID ** riids)
{
	if (celt <= 0UL)
		return 0UL;
	else
	{
		*riids[0] = __uuidof(Pack1);
		return 1UL;
	}
}

}
