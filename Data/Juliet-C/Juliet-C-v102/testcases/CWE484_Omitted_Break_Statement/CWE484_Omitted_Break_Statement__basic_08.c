/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE484_Omitted_Break_Statement__basic_08.c
Label Definition File: CWE484_Omitted_Break_Statement__basic.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 484 Omitted Break Statement
 * Sinks:
 *    GoodSink: Use breaks at the end of cases to prevent fall through
 *    BadSink : No break at the end of cases
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int static_returns_t()
{
    return 1;
}

static int static_returns_f()
{
    return 0;
}

#ifndef OMITBAD

void CWE484_Omitted_Break_Statement__basic_08_bad()
{
    if(static_returns_t())
    {
        {
            int x;
            x = (rand() % 3);
            /* FLAW: None of these cases ends in a break */
            switch (x)
            {
            case 0:
                printLine("0");
            case 1:
                printLine("1");
                break;
            case 2:
                printLine("2");
                break;
                /* no default case, but there shouldn't be one */
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int x;
            x = (rand() % 3);
            /* FIX: Use break in all cases that you do not intend "fall-through"
             * behavior */
            switch (x)
            {
            case 0:
                printLine("0");
                break;
            case 1:
                printLine("1");
                break;
            case 2:
                printLine("2");
                break;
                /* no default case, but there shouldn't be one */
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_returns_f()) instead of if(static_returns_t()) */
static void good1()
{
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int x;
            x = (rand() % 3);
            /* FLAW: None of these cases ends in a break */
            switch (x)
            {
            case 0:
                printLine("0");
            case 1:
                printLine("1");
                break;
            case 2:
                printLine("2");
                break;
                /* no default case, but there shouldn't be one */
            }
        }
    }
    else
    {
        {
            int x;
            x = (rand() % 3);
            /* FIX: Use break in all cases that you do not intend "fall-through"
             * behavior */
            switch (x)
            {
            case 0:
                printLine("0");
                break;
            case 1:
                printLine("1");
                break;
            case 2:
                printLine("2");
                break;
                /* no default case, but there shouldn't be one */
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_returns_t())
    {
        {
            int x;
            x = (rand() % 3);
            /* FIX: Use break in all cases that you do not intend "fall-through"
             * behavior */
            switch (x)
            {
            case 0:
                printLine("0");
                break;
            case 1:
                printLine("1");
                break;
            case 2:
                printLine("2");
                break;
                /* no default case, but there shouldn't be one */
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int x;
            x = (rand() % 3);
            /* FLAW: None of these cases ends in a break */
            switch (x)
            {
            case 0:
                printLine("0");
            case 1:
                printLine("1");
                break;
            case 2:
                printLine("2");
                break;
                /* no default case, but there shouldn't be one */
            }
        }
    }
}

void CWE484_Omitted_Break_Statement__basic_08_good()
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
    CWE484_Omitted_Break_Statement__basic_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE484_Omitted_Break_Statement__basic_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif