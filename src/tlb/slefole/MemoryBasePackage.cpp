// MemoryBasePackage.cpp : CMemoryBasePackage ��ʵ��

#include "stdafx.h"
#include "MemoryBasePackage.h"


// CMemoryBasePackage

#include <comutil.h>

STDMETHODIMP CMemoryBasePackage::Serialize(byte** ppData, ULONG* pLength)
{
	// TODO: �ڴ����ʵ�ִ���
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
