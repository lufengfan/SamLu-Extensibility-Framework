#pragma once

#include "exports.h"

EXTERN_C
{

typedef HANDLE HCONTENT;
WIN32TEST1_API unsigned long WINAPI GetContentIIDCount(void);
WIN32TEST1_API unsigned long WINAPI GetContentIIDs(_In_ unsigned long celt, _In_ _Out_ IID **riids);
WIN32TEST1_API HRESULT WINAPI CreateInstance(_In_ IID iid, HCONTENT *phContent);
WIN32TEST1_API void WINAPI Release(HCONTENT hContent);

}
