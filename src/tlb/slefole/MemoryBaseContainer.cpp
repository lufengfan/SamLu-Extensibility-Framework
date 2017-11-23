// MemoryBaseContainer.cpp : CMemoryBaseContainer 的实现

#include "stdafx.h"
#include "MemoryBaseContainer.h"


// CMemoryBaseContainer

#include <comutil.h>

STDMETHODIMP CMemoryBaseContainer::Initialize(void)
{
	return S_OK;
}

STDMETHODIMP CMemoryBaseContainer::Dispose(void)
{
	return S_OK;
}

STDMETHODIMP CMemoryBaseContainer::get_Contents(IEnumContents** pVal)
{
	*pVal = NULL;
	return S_FALSE;
}

#include "MemoryBasePackage.h"
STDMETHODIMP CMemoryBaseContainer::Deserialize(ULONG length, byte* pData, IMemoryBasePackage** ppPackage)
{
	// TODO: 在此添加实现代码
	
	CoInitialize(NULL);
	HRESULT hr = CoCreateInstance(CLSID_MemoryBasePackage, NULL, CLSCTX_INPROC_SERVER, IID_IMemoryBasePackage, (void**)ppPackage);
	CoUninitialize();

	return hr;
}
