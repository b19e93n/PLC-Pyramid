/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__char_declare_ncpy_15.c
Label Definition File: CWE124_Buffer_Underwrite.stack.label.xml
Template File: sources-sink-15.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: ncpy
 *    BadSink : Copy string to data using strncpy
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE124_Buffer_Underwrite__char_declare_ncpy_15_bad()
{
    char * data;
    char data_buf[100];
    memset(data_buf, 'A', 100-1);
    data_buf[100-1] = '\0';
    switch(6)
    {
    case 6:
        /* FLAW: Set data pointer to before the allocated memory buffer */
        data = data_buf - 8;
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Set data pointer to the allocated memory buffer */
        data = data_buf;
        break;
    }
    {
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
        strncpy(data, src, 100);
        /* Ensure the destination buffer is null terminated */
        data[100-1] = '\0';
        printLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the switch to switch(5) */
static void goodG2B1()
{
    char * data;
    char data_buf[100];
    memset(data_buf, 'A', 100-1);
    data_buf[100-1] = '\0';
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Set data pointer to before the allocated memory buffer */
        data = data_buf - 8;
        break;
    default:
        /* FIX: Set data pointer to the allocated memory buffer */
        data = data_buf;
        break;
    }
    {
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
        strncpy(data, src, 100);
        /* Ensure the destination buffer is null terminated */
        data[100-1] = '\0';
        printLine(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the switch */
static void goodG2B2()
{
    char * data;
    char data_buf[100];
    memset(data_buf, 'A', 100-1);
    data_buf[100-1] = '\0';
    switch(6)
    {
    case 6:
        /* FIX: Set data pointer to the allocated memory buffer */
        data = data_buf;
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Set data pointer to before the allocated memory buffer */
        data = data_buf - 8;
        break;
    }
    {
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
        strncpy(data, src, 100);
        /* Ensure the destination buffer is null terminated */
        data[100-1] = '\0';
        printLine(data);
    }
}

void CWE124_Buffer_Underwrite__char_declare_ncpy_15_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE124_Buffer_Underwrite__char_declare_ncpy_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE124_Buffer_Underwrite__char_declare_ncpy_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif