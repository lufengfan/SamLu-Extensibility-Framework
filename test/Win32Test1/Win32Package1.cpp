#include "stdafx.h"
#include "ContainerContents.h"

using namespace Win32Test1;

Win32Package1::Win32Package1() {}
Win32Package1::~Win32Package1() {}

HRESULT __stdcall Win32Package1::raw_Initialize(
	/*[out,retval]*/ HRESULT * pRetVal)
{
	return S_OK;
}

HRESULT __stdcall Win32Package1::raw_EnumContents(
	/*[out]*/ struct IEnumContent * * ppenum,
	/*[out,retval]*/ HRESULT * pRetVal)
{
	ppenum = NULL;
	return E_NOTIMPL;
}
