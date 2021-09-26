// util.cpp

#include "util.h"


//=============================================================================
// Logger
//=============================================================================


static FILE* fpLog;


void LogInit(LPCWSTR lpFileName)
{
    _wfopen_s(&fpLog, lpFileName, L"wt");
}


void LogWrite(LPCSTR lpMessage, ...)
{
    va_list args;

    va_start(args, lpMessage);
    vfprintf(fpLog, lpMessage, args);
    va_end(args);
    fflush(fpLog);
}


void LogWrite(LPCWSTR lpMessage, ...)
{
    va_list args;

    va_start(args, lpMessage);
    vfwprintf(fpLog, lpMessage, args);
    va_end(args);
    fflush(fpLog);
}


//=============================================================================
// Pattern Search Helper
//=============================================================================


PVOID GetModuleBase(HMODULE hModule)
{
    MEMORY_BASIC_INFORMATION mem;

    if (!VirtualQuery(hModule, &mem, sizeof(mem)))
        return NULL;

    return mem.AllocationBase;
}


DWORD GetModuleSize(HMODULE hModule)
{
    return ((IMAGE_NT_HEADERS*)((DWORD_PTR)hModule + ((IMAGE_DOS_HEADER*)hModule)->e_lfanew))->OptionalHeader.SizeOfImage;
}


ULONG SearchSignature(ULONG SearchAddress, ULONG SearchLength, PCSTR Signature, ULONG SignatureLength)
{
    auto s1 = reinterpret_cast<std::string_view::const_pointer>(SearchAddress);
    auto n1 = static_cast<std::string_view::size_type>(SearchLength);
    auto s2 = reinterpret_cast<std::string_view::const_pointer>(Signature);
    auto n2 = static_cast<std::string_view::size_type>(SignatureLength);

    std::string_view v1(s1, n1);
    std::string_view v2(s1, n2);

    auto pred = [](auto a, auto b) -> bool
    {
        return (b == 0x2a) || (a == b);
    };

    auto it = std::search(v1.begin(), v1.end(), v2.begin(), v2.end(), pred);

    if (it == v1.end())
        return NULL;

    return it - v1.begin() + SearchAddress;
}


//=============================================================================
// Patch Helper
//=============================================================================


void PatchRead(LPVOID lpAddr, LPVOID lpBuf, DWORD nSize)
{
    _ASSERT(lpAddr != NULL);
    _ASSERT(lpBuf != NULL);
    _ASSERT(nSize != 0);

    DWORD dwProtect;
    if (VirtualProtect(lpAddr, nSize, PAGE_EXECUTE_READWRITE, &dwProtect))
    {
        CopyMemory(lpBuf, lpAddr, nSize);
        VirtualProtect(lpAddr, nSize, dwProtect, &dwProtect);
    }
    else
    {
        FatalError("Failed to modify protection at %08X !", lpAddr);
    }
}


void PatchWrite(LPVOID lpAddr, LPCVOID lpBuf, DWORD nSize)
{
    _ASSERT(lpAddr != NULL);
    _ASSERT(lpBuf != NULL);
    _ASSERT(nSize != 0);

    DWORD dwProtect;
    if (VirtualProtect(lpAddr, nSize, PAGE_EXECUTE_READWRITE, &dwProtect))
    {
        CopyMemory(lpAddr, lpBuf, nSize);
        VirtualProtect(lpAddr, nSize, dwProtect, &dwProtect);
    }
    else
    {
        FatalError("Failed to modify protection at %08X !", lpAddr);
    }
}


void PatchNop(LPVOID lpAddr, int nCount)
{
    _ASSERT(lpAddr != NULL);
    _ASSERT(nCount != 0);

    DWORD dwProtect;
    if (VirtualProtect(lpAddr, nCount, PAGE_EXECUTE_READWRITE, &dwProtect))
    {
        memset(lpAddr, 0x90, nCount);
        VirtualProtect(lpAddr, nCount, dwProtect, &dwProtect);
    }
    else
    {
        FatalError("Failed to modify protection at %08X !", lpAddr);
    }
}


void PatchWriteStringA(LPVOID lpAddr, LPCSTR lpBuf)
{
    _ASSERT(lpAddr != NULL);
    _ASSERT(lpBuf != NULL);
    DWORD srcLen = strlen((LPCSTR)lpAddr);
    DWORD newLen = strlen(lpBuf);
    if (newLen > srcLen)
        FatalError("PatchWriteStringA: No enough space.");
    DWORD nSize = newLen + 1;
    PatchWrite(lpAddr, lpBuf, nSize);
}


void PatchWriteStringW(LPVOID lpAddr, LPCWSTR lpBuf)
{
    _ASSERT(lpAddr != NULL);
    _ASSERT(lpBuf != NULL);
    DWORD srcLen = wcslen((LPCWSTR)lpAddr);
    DWORD newLen = wcslen(lpBuf);
    if (newLen > srcLen)
        FatalError("PatchWriteStringW: No enough space.");
    DWORD nSize = (newLen + 1) * sizeof(WCHAR);
    PatchWrite(lpAddr, lpBuf, nSize);
}


//=============================================================================
// Hook Helper
//=============================================================================


static inline PBYTE RvaAdjust(_Pre_notnull_ PIMAGE_DOS_HEADER pDosHeader, _In_ DWORD raddr)
{
    if (raddr != NULL) {
        return ((PBYTE)pDosHeader) + raddr;
    }
    return NULL;
}


BOOL IATHook(HMODULE hModule, PCSTR pszFileName, PCSTR pszProcName, DWORD dwOrdinal, PVOID pNewProc)
{
    _ASSERT(pszFileName != NULL);
    _ASSERT(pszProcName != NULL || dwOrdinal != 0xFFFFFFFF);
    _ASSERT(pNewProc != NULL);

    PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)hModule;

    if (hModule == NULL)
        pDosHeader = (PIMAGE_DOS_HEADER)GetModuleHandleW(NULL);

    if (pDosHeader->e_magic != IMAGE_DOS_SIGNATURE)
        return FALSE;

    PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)((PBYTE)pDosHeader + pDosHeader->e_lfanew);

    if (pNtHeader->Signature != IMAGE_NT_SIGNATURE)
        return FALSE;

    if (pNtHeader->FileHeader.SizeOfOptionalHeader == 0)
        return FALSE;

    PIMAGE_IMPORT_DESCRIPTOR iidp = (PIMAGE_IMPORT_DESCRIPTOR)RvaAdjust(pDosHeader, pNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);

    if (iidp == NULL)
        return FALSE;

    for (; iidp->OriginalFirstThunk != 0; iidp++)
    {
        PCSTR pszName = (PCHAR)RvaAdjust(pDosHeader, iidp->Name);

        if (pszName == NULL)
            return FALSE;

        if (_stricmp(pszName, pszFileName) != 0)
            continue;

        PIMAGE_THUNK_DATA pThunks = (PIMAGE_THUNK_DATA)RvaAdjust(pDosHeader, iidp->OriginalFirstThunk);
        PVOID* pAddrs = (PVOID*)RvaAdjust(pDosHeader, iidp->FirstThunk);

        if (pThunks == NULL)
            continue;

        for (DWORD nNames = 0; pThunks[nNames].u1.Ordinal; nNames++)
        {
            DWORD nOrdinal = 0;
            PCSTR pszFunc = NULL;

            if (IMAGE_SNAP_BY_ORDINAL(pThunks[nNames].u1.Ordinal))
                nOrdinal = (DWORD)IMAGE_ORDINAL(pThunks[nNames].u1.Ordinal);
            else
                pszFunc = (PCSTR)RvaAdjust(pDosHeader, (DWORD)pThunks[nNames].u1.AddressOfData + 2);

            if (pszFunc == NULL)
                continue;

            if (pszProcName)
            {
                if (strcmp(pszFunc, pszProcName) != 0)
                    continue;
            }
            else if (dwOrdinal != 0xFFFFFFFF)
            {
                if (nOrdinal != dwOrdinal)
                    continue;
            }
            else
            {
                continue;
            }

            PatchWrite(&pAddrs[nNames], pNewProc);
            return TRUE;
        }
    }

    return FALSE;
}


//=============================================================================
// Encoding
//=============================================================================


CStringW AnsiToUcs2(int cp, const CStringA& str)
{
    if (str.GetLength() == 0)
        return CStringW();
    int nLen = MultiByteToWideChar(cp, 0, str.GetString(), str.GetLength(), NULL, 0);
    if (nLen == 0)
        return CStringW();
    CStringW ret(L'\0', nLen);
    if (MultiByteToWideChar(cp, 0, str.GetString(), str.GetLength(), ret.GetBuffer(), ret.GetAllocLength()) == 0)
        return CStringW();
    return ret;
}


CStringA Ucs2ToAnsi(int cp, const CStringW& str, LPCCH defChar)
{
    if (str.GetLength() == 0)
        return CStringA();
    int nLen = WideCharToMultiByte(cp, 0, str.GetString(), str.GetLength(), NULL, 0, NULL, NULL);
    if (nLen == 0)
        return CStringA();
    CStringA ret('\0', nLen);
    if (WideCharToMultiByte(cp, 0, str.GetString(), str.GetLength(), ret.GetBuffer(), ret.GetAllocLength(), defChar, NULL) == 0)
        return CStringA();
    return ret;
}


CStringW Utf8ToUcs2(const CStringA& str)
{
    return AnsiToUcs2(CP_UTF8, str);
}


CStringA Ucs2ToUtf8(const CStringW& str)
{
    return Ucs2ToAnsi(CP_UTF8, str, "?");
}


CStringW ShiftJisToUcs2(const CStringA& str)
{
    return AnsiToUcs2(CP_SHIFTJIS, str);
}


CStringA Ucs2ToShiftJis(const CStringW& str)
{
    return Ucs2ToAnsi(CP_SHIFTJIS, str, "?");
}


CStringW GbkToUcs2(const CStringA& str)
{
    return AnsiToUcs2(CP_GBK, str);
}


CStringA Ucs2ToGbk(const CStringW& str)
{
    return Ucs2ToAnsi(CP_GBK, str, "?");
}


//=============================================================================
// String Helper
//=============================================================================


void ConvertStringCodePage(LPSTR lpBuf, int srcCP, int dstCP, LPCCH defChar)
{
    _ASSERT(lpBuf != NULL);
    CStringW ucs = AnsiToUcs2(srcCP, lpBuf);
    CStringA ansi = Ucs2ToAnsi(dstCP, ucs, defChar);
    PatchWriteStringA(lpBuf, ansi);
}


//=============================================================================
// File & Path
//=============================================================================


CPathA GetAppDirectoryA()
{
    CHAR szPath[MAX_PATH];
    GetModuleFileNameA(GetModuleHandleA(NULL), szPath, ARRAYSIZE(szPath));
    if (GetLastError() != ERROR_SUCCESS)
        return CPathA();
    CPathA ret(szPath);
    if (ret.RemoveFileSpec() != TRUE)
        return CPathA();
    return ret;
}


CPathW GetAppDirectoryW()
{
    WCHAR szPath[MAX_PATH];
    GetModuleFileNameW(GetModuleHandleW(NULL), szPath, ARRAYSIZE(szPath));
    if (GetLastError() != ERROR_SUCCESS)
        return CPathW();
    CPathW ret(szPath);
    if (ret.RemoveFileSpec() != TRUE)
        return CPathW();
    return ret;
}


CPathA GetAppPathA()
{
    CHAR szPath[MAX_PATH];
    GetModuleFileNameA(GetModuleHandleA(NULL), szPath, ARRAYSIZE(szPath));
    if (GetLastError() != ERROR_SUCCESS)
        return CPathA();
    return CPathA(szPath);
}


CPathW GetAppPathW()
{
    WCHAR szPath[MAX_PATH];
    GetModuleFileNameW(GetModuleHandleW(NULL), szPath, ARRAYSIZE(szPath));
    if (GetLastError() != ERROR_SUCCESS)
        return CPathW();
    return CPathW(szPath);
}


//=============================================================================
// Error Handling
//=============================================================================


__declspec(noreturn) void FatalError(LPCSTR lpMessage, ...)
{
    CStringA strMsg;
    va_list args;

    va_start(args, lpMessage);
    strMsg.FormatV(lpMessage, args);
    va_end(args);

    MessageBoxA(GetActiveWindow(), strMsg, "Fatal Error", MB_OK | MB_ICONERROR);
    ExitProcess(1);
}


__declspec(noreturn) void FatalError(LPCWSTR lpMessage, ...)
{
    CStringW strMsg;
    va_list args;

    va_start(args, lpMessage);
    strMsg.FormatV(lpMessage, args);
    va_end(args);

    MessageBoxW(GetActiveWindow(), strMsg, L"Fatal Error", MB_OK | MB_ICONERROR);
    ExitProcess(1);
}


//=============================================================================
// PE Helper
//=============================================================================


PIMAGE_SECTION_HEADER FindSectionFromModule(HMODULE hModule, PCSTR pName)
{
    PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)hModule;

    if (hModule == NULL)
        pDosHeader = (PIMAGE_DOS_HEADER)GetModuleHandleW(NULL);

    if (pDosHeader->e_magic != IMAGE_DOS_SIGNATURE)
        return NULL;

    PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)((PBYTE)pDosHeader + pDosHeader->e_lfanew);

    if (pNtHeader->Signature != IMAGE_NT_SIGNATURE)
        return NULL;

    if (pNtHeader->FileHeader.SizeOfOptionalHeader == 0)
        return NULL;

    PIMAGE_SECTION_HEADER pSectionHeaders = (PIMAGE_SECTION_HEADER)((PBYTE)pNtHeader + sizeof(pNtHeader->Signature) + sizeof(pNtHeader->FileHeader) + pNtHeader->FileHeader.SizeOfOptionalHeader);

    for (DWORD n = 0; n < pNtHeader->FileHeader.NumberOfSections; n++)
    {
        if (strcmp((PCHAR)pSectionHeaders[n].Name, pName) == 0)
        {
            if (pSectionHeaders[n].VirtualAddress == 0 || pSectionHeaders[n].SizeOfRawData == 0)
                return NULL;

            return &pSectionHeaders[n];
        }
    }

    return NULL;
}


//=============================================================================
// GUI
//=============================================================================


#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


static HANDLE ActCtx = INVALID_HANDLE_VALUE;
static ULONG_PTR ActCookie = 0;

void InitComCtl(HMODULE hModule)
{
    if (ActCtx != INVALID_HANDLE_VALUE)
        return;

    ACTCTXW ctx = {};
    ctx.cbSize = sizeof(ctx);
    ctx.dwFlags = ACTCTX_FLAG_HMODULE_VALID | ACTCTX_FLAG_RESOURCE_NAME_VALID;
    ctx.lpResourceName = MAKEINTRESOURCEW(2);
    ctx.hModule = hModule;
    // This sample implies your DLL stores Common Controls version 6.0 manifest in its resources with ID 2.

    ActCtx = CreateActCtxW(&ctx);

    if (ActCtx == INVALID_HANDLE_VALUE)
        return;

    ActivateActCtx(ActCtx, &ActCookie);
}


void ReleaseComCtl()
{
    if (ActCtx == INVALID_HANDLE_VALUE)
        return;

    DeactivateActCtx(0, ActCookie);
    ReleaseActCtx(ActCtx);
}

