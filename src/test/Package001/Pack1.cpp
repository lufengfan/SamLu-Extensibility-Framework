#include "stdafx.h"
#include "Pack1.h"

STDMETHODIMP CPack1::raw_Initialize()
{
	printf_s("Pack1 Initialize.");
	return S_OK;
}

STDMETHODIMP CPack1::raw_Dispose()
{
	printf_s("Pack1 Dispose.");
	return S_OK;
}

STDMETHODIMP CPack1::get_Contents(
	/*[out,retval]*/ struct IEnumContents * * pVal)
{
	*pVal = NULL;
	return E_NOTIMPL;
}
