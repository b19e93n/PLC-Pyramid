/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_34.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: fromConsole Read input from the console
 * GoodSource: Use a hardcoded path
 * Sinks:
 *    BadSink : Set the environment variable
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define NEW_PATH "%SystemRoot%\\system32"
# define PUTENV _putenv
#else
# define NEW_PATH "/bin"
# define PUTENV putenv
#endif

typedef union
{
    char * a;
    char * b;
} CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_34_union_type;

#ifndef OMITBAD

void CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_34_bad()
{
    char * data;
    CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_34_union_type my_union;
    char data_buf[250] = "PATH=";
    data = data_buf;
    {
        /* Read input from the console */
        size_t data_len = strlen(data);
        /* if there is room in data, read into it from the console */
        if(250-data_len > 1)
        {
            fgets(data+data_len, (int)(250-data_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgets() */
            data_len = strlen(data);
            if (data_len > 0)
            {
                data[data_len-1] = '\0';
            }
        }
    }
    my_union.a = data;
    {
        char * data = my_union.b;
        /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
        PUTENV(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_34_union_type my_union;
    char data_buf[250] = "PATH=";
    data = data_buf;
    /* FIX: Set the path as the "system" path */
    strcat(data, NEW_PATH);
    my_union.a = data;
    {
        char * data = my_union.b;
        /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
        PUTENV(data);
    }
}

void CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_34_good()
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
    CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif