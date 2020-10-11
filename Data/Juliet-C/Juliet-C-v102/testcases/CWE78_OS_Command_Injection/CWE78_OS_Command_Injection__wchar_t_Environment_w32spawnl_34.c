/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_Environment_w32spawnl_34.c
Label Definition File: CWE78_OS_Command_Injection.no_path.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Benign input
 * Sinks: w32spawnl
 *    BadSink : execute command with wspawnl
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define COMMAND_INT_PATH L"%WINDIR%\\system32\\cmd.exe"
# define COMMAND_INT L"cmd.exe"
# define COMMAND_ARG1 L"/c"
# define COMMAND_ARG2 L"dir"
# define COMMAND_ARG3 data
#else /* NOT _WIN32 */
# define COMMAND_INT_PATH L"/bin/sh"
# define COMMAND_INT L"sh"
# define COMMAND_ARG1 L"ls"
# define COMMAND_ARG2 data
# define COMMAND_ARG3 NULL
#endif

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
# define GETENV _wgetenv
#else
# define GETENV wgetenv
#endif

#include <process.h>

typedef union
{
    wchar_t * a;
    wchar_t * b;
} CWE78_OS_Command_Injection__wchar_t_Environment_w32spawnl_34_union_type;

#ifndef OMITBAD

void CWE78_OS_Command_Injection__wchar_t_Environment_w32spawnl_34_bad()
{
    wchar_t * data;
    CWE78_OS_Command_Injection__wchar_t_Environment_w32spawnl_34_union_type my_union;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    {
        /* Read input from an environment variable */
        size_t data_len = wcslen(data);
        wchar_t * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            wcsncat(data+data_len, environment, 100-data_len-1);
        }
    }
    my_union.a = data;
    {
        wchar_t * data = my_union.b;
        /* wspawnl - specify the path where the command is located */
        /* POSSIBLE FLAW: Execute command without validating input possibly leading to command injection */
        _wspawnl(_P_WAIT, COMMAND_INT_PATH, COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    CWE78_OS_Command_Injection__wchar_t_Environment_w32spawnl_34_union_type my_union;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    /* FIX: Benign input preventing command injection */
    wcscat(data, L"*.*");
    my_union.a = data;
    {
        wchar_t * data = my_union.b;
        /* wspawnl - specify the path where the command is located */
        /* POSSIBLE FLAW: Execute command without validating input possibly leading to command injection */
        _wspawnl(_P_WAIT, COMMAND_INT_PATH, COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL);
    }
}

void CWE78_OS_Command_Injection__wchar_t_Environment_w32spawnl_34_good()
{
    goodG2B();
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
    CWE78_OS_Command_Injection__wchar_t_Environment_w32spawnl_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE78_OS_Command_Injection__wchar_t_Environment_w32spawnl_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif