/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__char_system_68a.c
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * BadSource:  Don't specify the full path in the OS command
 * GoodSource: Specify the full path in the OS command
 * Sink: system
 *    BadSink : Execute the system function
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
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

char * CWE426_Untrusted_Search_Path__char_system_68_bad_data;
char * CWE426_Untrusted_Search_Path__char_system_68_goodG2B_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE426_Untrusted_Search_Path__char_system_68b_bad_sink();

void CWE426_Untrusted_Search_Path__char_system_68_bad()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    /* FLAW - the full path is not specified */
    strcpy(data, BAD_OS_COMMAND);
    CWE426_Untrusted_Search_Path__char_system_68_bad_data = data;
    CWE426_Untrusted_Search_Path__char_system_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE426_Untrusted_Search_Path__char_system_68b_goodG2B_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    /* FIX - full path is specified */
    strcpy(data, GOOD_OS_COMMAND);
    CWE426_Untrusted_Search_Path__char_system_68_goodG2B_data = data;
    CWE426_Untrusted_Search_Path__char_system_68b_goodG2B_sink();
}

void CWE426_Untrusted_Search_Path__char_system_68_good()
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
    CWE426_Untrusted_Search_Path__char_system_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE426_Untrusted_Search_Path__char_system_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif