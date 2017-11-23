#pragma once

#include "export.h"

EXTERN_C
{

PACKAGE001_API ULONG WINAPI GetContentIIDCount();
PACKAGE001_API ULONG WINAPI GetContentIIDs(_In_ ULONG celt, _In_ _Out_ GUID ** riids);

}
