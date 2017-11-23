#include "stdafx.h"
#include "_IUnknown_Base.h"


_IUnknown_Base::_IUnknown_Base() :m_nRef(0) {}

_IUnknown_Base::~_IUnknown_Base() {}

#pragma region IUnknown
HRESULT STDMETHODCALLTYPE _IUnknown_Base::QueryInterface(
	/* [in] */ REFIID riid,
	/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR *__RPC_FAR *ppvObject)
{
	if (riid == __uuidof(IUnknown))
	{
		*ppvObject = (IUnknown*)this;
		((IUnknown*)*ppvObject)->AddRef();
		return S_OK;
	}
	else
	{
		*ppvObject = NULL;
		return E_NOINTERFACE;
	}
}
ULONG STDMETHODCALLTYPE _IUnknown_Base::AddRef(void)
{
	m_nRef++;
	return m_nRef;
}
ULONG STDMETHODCALLTYPE _IUnknown_Base::Release(void)
{
	m_nRef--;
	if (m_nRef == 0)
	{
		delete this;
	}
	return m_nRef;
}
#pragma endregion
