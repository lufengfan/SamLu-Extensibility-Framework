// MemoryBasePackage.cpp : CMemoryBasePackage 的实现

#include "stdafx.h"
#include "MemoryBasePackage.h"


// CMemoryBasePackage

#include <comutil.h>

STDMETHODIMP CMemoryBasePackage::Serialize(byte** ppData, ULONG* pLength)
{
	// TODO: 在此添加实现代码
	int buffer_length = 256;
	byte *buffer = (byte*)malloc(sizeof(byte) * buffer_length);
	printf_s("Create buffer for length %d.\n", buffer_length);
	printf_s("Serializing...\n");
	printf_s("Write all bytes.\n");
	*ppData[0] = (byte)1;
	*ppData[255] = (byte)1;

	*ppData = buffer;

	return S_OK;
}
