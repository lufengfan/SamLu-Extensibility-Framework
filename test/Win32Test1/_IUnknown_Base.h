#pragma once
#include "Unknwnbase.h"
class _IUnknown_Base :
	public IUnknown
{
private:
	int m_nRef;

public:
	_IUnknown_Base();
	~_IUnknown_Base();

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(
		/* [in] */ REFIID riid,
		/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR *__RPC_FAR *ppvObject);
	virtual ULONG STDMETHODCALLTYPE AddRef(void);
	virtual ULONG STDMETHODCALLTYPE Release(void);
};

