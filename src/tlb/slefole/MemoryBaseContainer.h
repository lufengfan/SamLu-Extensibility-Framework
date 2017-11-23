// MemoryBaseContainer.h : CMemoryBaseContainer ������

#pragma once
#include "resource.h"       // ������



#include "slefole_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


// CMemoryBaseContainer

class ATL_NO_VTABLE CMemoryBaseContainer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMemoryBaseContainer, &CLSID_MemoryBaseContainer>,
	public IDispatchImpl<IMemoryBaseContainer, &IID_IMemoryBaseContainer, &LIBID_slefole, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CMemoryBaseContainer()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MEMORYBASECONTAINER)


BEGIN_COM_MAP(CMemoryBaseContainer)
	COM_INTERFACE_ENTRY(IMemoryBaseContainer)
	COM_INTERFACE_ENTRY(IAnyBaseContainer)
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

	STDMETHOD(Initialize)(void);

	STDMETHOD(Dispose)(void);

	STDMETHOD(get_Contents)(IEnumContents** pVal);

	STDMETHOD(Deserialize)(ULONG length, byte* pData, IMemoryBasePackage** ppPackage);
};

OBJECT_ENTRY_AUTO(__uuidof(MemoryBaseContainer), CMemoryBaseContainer)
