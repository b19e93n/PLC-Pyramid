/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__w32ImpersonateSelf_06.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-flaw-06.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: w32ImpersonateSelf
 *    GoodSink: Check the return value of ImpersonateSelf() and handle it properly
 *    BadSink : Do not check if ImpersonateSelf() fails
 * Flow Variant: 06 Control flow: if(static_const_five==5) and if(static_const_five!=5)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
# pragma comment(lib, "advapi32")

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int static_const_five = 5;

#ifndef OMITBAD

void CWE252_Unchecked_Return_Value__w32ImpersonateSelf_06_bad()
{
    if(static_const_five==5)
    {
        {
            /* FLAW: Do not check if ImpersonateSelf() fails */
            ImpersonateSelf(SecurityImpersonation);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: Check to see if ImpersonateSelf() fails */
            if (!ImpersonateSelf(SecurityImpersonation))
            {
                exit(1);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_const_five!=5) instead of if(static_const_five==5) */
static void good1()
{
    if(static_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: Do not check if ImpersonateSelf() fails */
            ImpersonateSelf(SecurityImpersonation);
        }
    }
    else
    {
        {
            /* FIX: Check to see if ImpersonateSelf() fails */
            if (!ImpersonateSelf(SecurityImpersonation))
            {
                exit(1);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_const_five==5)
    {
        {
            /* FIX: Check to see if ImpersonateSelf() fails */
            if (!ImpersonateSelf(SecurityImpersonation))
            {
                exit(1);
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: Do not check if ImpersonateSelf() fails */
            ImpersonateSelf(SecurityImpersonation);
        }
    }
}

void CWE252_Unchecked_Return_Value__w32ImpersonateSelf_06_good()
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
    CWE252_Unchecked_Return_Value__w32ImpersonateSelf_06_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__w32ImpersonateSelf_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif