// MemoryBasePackage.h : CMemoryBasePackage ������

#pragma once
#include "resource.h"       // ������



#include "slefole_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


// CMemoryBasePackage

class ATL_NO_VTABLE CMemoryBasePackage :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMemoryBasePackage, &CLSID_MemoryBasePackage>,
	public IDispatchImpl<IMemoryBasePackage, &IID_IMemoryBasePackage, &LIBID_slefole, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CMemoryBasePackage()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MEMORYBASEPACKAGE)


BEGIN_COM_MAP(CMemoryBasePackage)
	COM_INTERFACE_ENTRY(IMemoryBasePackage)
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



	STDMETHOD(Serialize)(byte** ppData, ULONG* pLength);
};

OBJECT_ENTRY_AUTO(__uuidof(MemoryBasePackage), CMemoryBasePackage)
