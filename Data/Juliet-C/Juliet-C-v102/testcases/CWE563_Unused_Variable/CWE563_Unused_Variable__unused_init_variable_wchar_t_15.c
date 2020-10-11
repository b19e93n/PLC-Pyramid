/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_init_variable_wchar_t_15.c
Label Definition File: CWE563_Unused_Variable__unused_init_variable.label.xml
Template File: source-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : do nothing
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE563_Unused_Variable__unused_init_variable_wchar_t_15_bad()
{
    wchar_t data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = L'W';
    switch(6)
    {
    case 6:
        /* POTENTIAL FLAW: Do not use the variable */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use data */
        printf("%02lx\n", data);
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the switch to switch(5) */
static void goodB2G1()
{
    wchar_t data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = L'W';
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Do not use the variable */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
        break;
    default:
        /* FIX: Use data */
        printf("%02lx\n", data);
        break;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the switch */
static void goodB2G2()
{
    wchar_t data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = L'W';
    switch(6)
    {
    case 6:
        /* FIX: Use data */
        printf("%02lx\n", data);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Do not use the variable */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
        break;
    }
}

void CWE563_Unused_Variable__unused_init_variable_wchar_t_15_good()
{
    goodB2G1();
    goodB2G2();
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
    CWE563_Unused_Variable__unused_init_variable_wchar_t_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_init_variable_wchar_t_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif