#pragma once

//#include <slefole_i.c>
#include <atlcom.h>
#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
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
