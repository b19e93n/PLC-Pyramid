/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__char_system_67a.c
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * BadSource:  Don't specify the full path in the OS command
 * GoodSource: Specify the full path in the OS command
 * Sinks: system
 *    BadSink : Execute the system function
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define BAD_OS_COMMAND "cmd.exe /c dir"

/* REVIEWERS NOTE:
 * This hard-coded path is probably incorrect for Windows systems, as it will
 * function improperly on 9x/NT/2K, possibly on XP+ systems upgraded from 2K,
 * and could introduce code execution vulnerabilities on Windows systems that
 * have a system drive on an alternate drive letter (e.g., d:\windows)
 */
# define GOOD_OS_COMMAND "c:\\windows\\system32\\cmd.exe /c dir"
#else /* NOT _WIN32 */
# define BAD_OS_COMMAND "ls -la"
# define GOOD_OS_COMMAND "/usr/bin/ls -la"
#endif /* end NOT _WIN32 */

typedef struct _CWE426_Untrusted_Search_Path__char_system_67_struct_type
{
    char * a;
} CWE426_Untrusted_Search_Path__char_system_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE426_Untrusted_Search_Path__char_system_67b_bad_sink(CWE426_Untrusted_Search_Path__char_system_67_struct_type my_struct);

void CWE426_Untrusted_Search_Path__char_system_67_bad()
{
    char * data;
    CWE426_Untrusted_Search_Path__char_system_67_struct_type my_struct;
    char data_buf[100] = "";
    data = data_buf;
    /* FLAW - the full path is not specified */
    strcpy(data, BAD_OS_COMMAND);
    my_struct.a = data;
    CWE426_Untrusted_Search_Path__char_system_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE426_Untrusted_Search_Path__char_system_67b_goodG2B_sink(CWE426_Untrusted_Search_Path__char_system_67_struct_type my_struct);

static void goodG2B()
{
    char * data;
    CWE426_Untrusted_Search_Path__char_system_67_struct_type my_struct;
    char data_buf[100] = "";
    data = data_buf;
    /* FIX - full path is specified */
    strcpy(data, GOOD_OS_COMMAND);
    my_struct.a = data;
    CWE426_Untrusted_Search_Path__char_system_67b_goodG2B_sink(my_struct);
}

void CWE426_Untrusted_Search_Path__char_system_67_good()
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
    CWE426_Untrusted_Search_Path__char_system_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE426_Untrusted_Search_Path__char_system_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif