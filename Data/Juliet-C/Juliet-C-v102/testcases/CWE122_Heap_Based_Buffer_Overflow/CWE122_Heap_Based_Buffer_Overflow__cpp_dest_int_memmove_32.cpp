/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_dest_int_memmove_32.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_dest.label.xml
Template File: sources-sink-32.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sink: memmove
 *    BadSink : Copy int array to data using memmove
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_int_memmove_32
{

#ifndef OMITBAD

void bad()
{
    int * data;
    int * *data_ptr1 = &data;
    int * *data_ptr2 = &data;
    data = NULL;
    {
        int * data = *data_ptr1;
        /* FLAW: Allocate using new[] and point data to a small buffer that is smaller than the large buffer used in the sinks */
        data = new int[50];
        *data_ptr1 = data;
    }
    {
        int * data = *data_ptr2;
        {
            int src[100] = {0}; /* fill with 0's */
            /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
            memmove(data, src, 100*sizeof(int));
            printIntLine(data[0]);
            delete [] data;
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int * data;
    int * *data_ptr1 = &data;
    int * *data_ptr2 = &data;
    data = NULL;
    {
        int * data = *data_ptr1;
        /* FIX: Allocate using new[] and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = new int[100];
        *data_ptr1 = data;
    }
    {
        int * data = *data_ptr2;
        {
            int src[100] = {0}; /* fill with 0's */
            /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
            memmove(data, src, 100*sizeof(int));
            printIntLine(data[0]);
            delete [] data;
        }
    }
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

using namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_int_memmove_32; // so that we can use good and bad easily

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