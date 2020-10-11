/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__class_45.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference__class.label.xml
Template File: sources-sink-45.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    BadSink : Print data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

namespace CWE476_NULL_Pointer_Dereference__class_45
{

static twointsclass * bad_data;
static twointsclass * goodG2B_data;

#ifndef OMITBAD

static void bad_sink()
{
    twointsclass * data = bad_data;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printIntLine(data[0].a);
}

void bad()
{
    twointsclass * data;
    /* Initialize data */
    data = NULL;
    /* FLAW: Set data to NULL - it will be used in the sink */
    data = NULL;
    bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink()
{
    twointsclass * data = goodG2B_data;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printIntLine(data[0].a);
}

static void goodG2B()
{
    twointsclass * data;
    /* Initialize data */
    data = NULL;
    {
        twointsclass * tmp = new twointsclass;
        tmp->a = 0;
        tmp->b = 0;
        /* FIX: Initialize data - it will be used in the sink */
        data = tmp;
    }
    goodG2B_data = data;
    goodG2B_sink();
}

void good()
{
    goodG2B();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE476_NULL_Pointer_Dereference__class_45; // so that we can use good and bad easily

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif