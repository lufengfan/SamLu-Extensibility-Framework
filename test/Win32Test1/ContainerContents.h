#pragma once

#import "..\..\bin\slef.tlb" auto_search rename_namespace("SamLu::Extensibility")

namespace Win32Test1
{

#include "_IUnknown_Base.h"

	class __declspec(uuid("ec5b84ce-352f-4911-bb1d-01e78a8a6eda")) Win32Package1 :
		public _IUnknown_Base,
		public SamLu::Extensibility::IFileBasePackage
	{
	public:
		Win32Package1();
		~Win32Package1();

		virtual HRESULT STDMETHODCALLTYPE QueryInterface(
			/* [in] */ REFIID riid,
			/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR *__RPC_FAR *ppvObject)
		{
			if (E_NOINTERFACE == ((_IUnknown_Base*)this)->QueryInterface(riid, ppvObject))
			{
				if (riid == __uuidof(SamLu::Extensibility::IFileBasePackage))
				{
					*ppvObject = (SamLu::Extensibility::IFileBasePackage*)this;
					((SamLu::Extensibility::IFileBasePackage*)*ppvObject)->AddRef();
					return S_OK;
				}
				else
				{
					*ppvObject = NULL;
					return E_NOINTERFACE;
				}
			}
			else
			{
				return S_OK;
			}
		}
		virtual ULONG STDMETHODCALLTYPE AddRef(void)
		{
			((_IUnknown_Base*)this)->AddRef();
		}
		virtual ULONG STDMETHODCALLTYPE Release(void)
		{
			((_IUnknown_Base*)this)->Release();
		}

		virtual HRESULT __stdcall raw_Initialize(
			/*[out,retval]*/ HRESULT * pRetVal);
		virtual HRESULT __stdcall raw_EnumContents(
			/*[out]*/ struct IEnumContent * * ppenum,
			/*[out,retval]*/ HRESULT * pRetVal);
	};

}
