#pragma once

//#include <slefole_i.c>
#include <atlcom.h>
#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

#import "..\..\..\bin\slefole.dll"

using namespace ATL;

#define IDR_PACK1 501

// CPack1

#include <guiddef.h>
// {A03B77A8-FAF9-4484-AAFF-526D987767E0}
DEFINE_GUID(CLSID_Pack1,
	0xa03b77a8, 0xfaf9, 0x4484, 0xaa, 0xff, 0x52, 0x6d, 0x98, 0x77, 0x67, 0xe0);
DEFINE_GUID(IID_IFileBasePackage, 0xFA4126A8, 0x12AC, 0x4BB3, 0x83, 0xB4, 0x26, 0x8C, 0x24, 0xC9, 0x5C, 0x18);
DEFINE_GUID(LIBID_slefole, 0x9A60D56C, 0x95C9, 0x49BF, 0xA8, 0xDE, 0x87, 0x44, 0x61, 0x17, 0x8B, 0xCA);

class ATL_NO_VTABLE CPack1 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPack1, &CLSID_Pack1>,
	public IDispatchImpl<slefole::IFileBasePackage, &IID_IFileBasePackage, &LIBID_slefole, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CPack1() {}
	~CPack1() {}

	//DECLARE_REGISTRY_RESOURCEID(IDR_PACK1)


	BEGIN_COM_MAP(CPack1)
		COM_INTERFACE_ENTRY(IFileBasePackage)
		COM_INTERFACE_ENTRY(IUnknown)
	END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(raw_Initialize)();
	STDMETHOD(raw_Dispose)();
	STDMETHOD(get_Contents)(
		/*[out,retval]*/ struct IEnumContents * * pVal);

};

//OBJECT_ENTRY_AUTO(__uuidof(Pack1), CPack1)
