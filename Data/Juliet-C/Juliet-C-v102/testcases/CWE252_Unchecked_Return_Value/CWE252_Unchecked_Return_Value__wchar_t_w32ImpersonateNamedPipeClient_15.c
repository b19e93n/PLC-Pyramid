/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_15.c
Label Definition File: CWE252_Unchecked_Return_Value.string.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: w32ImpersonateNamedPipeClient
 *    GoodSink: Check the return value of CreateNamedPipeW() and handle it properly
 *    BadSink : Do not check if CreateNamedPipeW() fails
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
# pragma comment(lib, "advapi32")
#define BUFSIZE 1024

#ifndef OMITBAD

void CWE252_Unchecked_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_15_bad()
{
    switch(6)
    {
    case 6:
    {
        wchar_t * pipeName = L"\\\\.\\pipe\\mypipe";
        HANDLE hPipe = INVALID_HANDLE_VALUE;
        hPipe = CreateNamedPipeW(
                    pipeName,
                    FILE_FLAG_FIRST_PIPE_INSTANCE,
                    PIPE_TYPE_MESSAGE |
                    PIPE_READMODE_MESSAGE |
                    PIPE_WAIT,
                    PIPE_UNLIMITED_INSTANCES,
                    BUFSIZE,
                    BUFSIZE,
                    NMPWAIT_USE_DEFAULT_WAIT,
                    NULL);
        if (hPipe == INVALID_HANDLE_VALUE)
        {
            exit(1);
        }
        if (GetLastError() == ERROR_ACCESS_DENIED)
        {
            exit(1);
        }
        /* FLAW: Do not check the return value */
        ImpersonateNamedPipeClient(hPipe);
        CloseHandle(hPipe);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        wchar_t * pipeName = L"\\\\.\\pipe\\mypipe";
        HANDLE hPipe = INVALID_HANDLE_VALUE;
        hPipe = CreateNamedPipeW(
                    pipeName,
                    FILE_FLAG_FIRST_PIPE_INSTANCE,
                    PIPE_TYPE_MESSAGE |
                    PIPE_READMODE_MESSAGE |
                    PIPE_WAIT,
                    PIPE_UNLIMITED_INSTANCES,
                    BUFSIZE,
                    BUFSIZE,
                    NMPWAIT_USE_DEFAULT_WAIT,
                    NULL);
        if (hPipe == INVALID_HANDLE_VALUE)
        {
            exit(1);
        }
        if (GetLastError() == ERROR_ACCESS_DENIED)
        {
            exit(1);
        }
        /* FIX: Check to see if ImpersonateNamedPipeClient() fails */
        if (!ImpersonateNamedPipeClient(hPipe))
        {
            exit(1);
        }
        CloseHandle(hPipe);
    }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        wchar_t * pipeName = L"\\\\.\\pipe\\mypipe";
        HANDLE hPipe = INVALID_HANDLE_VALUE;
        hPipe = CreateNamedPipeW(
                    pipeName,
                    FILE_FLAG_FIRST_PIPE_INSTANCE,
                    PIPE_TYPE_MESSAGE |
                    PIPE_READMODE_MESSAGE |
                    PIPE_WAIT,
                    PIPE_UNLIMITED_INSTANCES,
                    BUFSIZE,
                    BUFSIZE,
                    NMPWAIT_USE_DEFAULT_WAIT,
                    NULL);
        if (hPipe == INVALID_HANDLE_VALUE)
        {
            exit(1);
        }
        if (GetLastError() == ERROR_ACCESS_DENIED)
        {
            exit(1);
        }
        /* FLAW: Do not check the return value */
        ImpersonateNamedPipeClient(hPipe);
        CloseHandle(hPipe);
    }
    break;
    default:
    {
        wchar_t * pipeName = L"\\\\.\\pipe\\mypipe";
        HANDLE hPipe = INVALID_HANDLE_VALUE;
        hPipe = CreateNamedPipeW(
                    pipeName,
                    FILE_FLAG_FIRST_PIPE_INSTANCE,
                    PIPE_TYPE_MESSAGE |
                    PIPE_READMODE_MESSAGE |
                    PIPE_WAIT,
                    PIPE_UNLIMITED_INSTANCES,
                    BUFSIZE,
                    BUFSIZE,
                    NMPWAIT_USE_DEFAULT_WAIT,
                    NULL);
        if (hPipe == INVALID_HANDLE_VALUE)
        {
            exit(1);
        }
        if (GetLastError() == ERROR_ACCESS_DENIED)
        {
            exit(1);
        }
        /* FIX: Check to see if ImpersonateNamedPipeClient() fails */
        if (!ImpersonateNamedPipeClient(hPipe))
        {
            exit(1);
        }
        CloseHandle(hPipe);
    }
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
    {
        wchar_t * pipeName = L"\\\\.\\pipe\\mypipe";
        HANDLE hPipe = INVALID_HANDLE_VALUE;
        hPipe = CreateNamedPipeW(
                    pipeName,
                    FILE_FLAG_FIRST_PIPE_INSTANCE,
                    PIPE_TYPE_MESSAGE |
                    PIPE_READMODE_MESSAGE |
                    PIPE_WAIT,
                    PIPE_UNLIMITED_INSTANCES,
                    BUFSIZE,
                    BUFSIZE,
                    NMPWAIT_USE_DEFAULT_WAIT,
                    NULL);
        if (hPipe == INVALID_HANDLE_VALUE)
        {
            exit(1);
        }
        if (GetLastError() == ERROR_ACCESS_DENIED)
        {
            exit(1);
        }
        /* FIX: Check to see if ImpersonateNamedPipeClient() fails */
        if (!ImpersonateNamedPipeClient(hPipe))
        {
            exit(1);
        }
        CloseHandle(hPipe);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        wchar_t * pipeName = L"\\\\.\\pipe\\mypipe";
        HANDLE hPipe = INVALID_HANDLE_VALUE;
        hPipe = CreateNamedPipeW(
                    pipeName,
                    FILE_FLAG_FIRST_PIPE_INSTANCE,
                    PIPE_TYPE_MESSAGE |
                    PIPE_READMODE_MESSAGE |
                    PIPE_WAIT,
                    PIPE_UNLIMITED_INSTANCES,
                    BUFSIZE,
                    BUFSIZE,
                    NMPWAIT_USE_DEFAULT_WAIT,
                    NULL);
        if (hPipe == INVALID_HANDLE_VALUE)
        {
            exit(1);
        }
        if (GetLastError() == ERROR_ACCESS_DENIED)
        {
            exit(1);
        }
        /* FLAW: Do not check the return value */
        ImpersonateNamedPipeClient(hPipe);
        CloseHandle(hPipe);
    }
    }
}

void CWE252_Unchecked_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_15_good()
{
    good1();
    good2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE252_Unchecked_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__wchar_t_w32ImpersonateNamedPipeClient_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif