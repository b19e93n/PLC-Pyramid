/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_dest_long_long_memmove_32.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_dest.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sink: memmove
 *    BadSink : Copy long long array to data using memmove
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_dest_long_long_memmove_32_bad()
{
    long long * data;
    long long * *data_ptr1 = &data;
    long long * *data_ptr2 = &data;
    data = NULL;
    {
        long long * data = *data_ptr1;
        /* FLAW: Allocate and point data to a small buffer that is smaller than the large buffer used in the sinks */
        data = (long long *)malloc(50*sizeof(long long));
        *data_ptr1 = data;
    }
    {
        long long * data = *data_ptr2;
        {
            long long src[100] = {0}; /* fill with 0's */
            /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
            memmove(data, src, 100*sizeof(long long));
            printLongLongLine(data[0]);
            free(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    long long * data;
    long long * *data_ptr1 = &data;
    long long * *data_ptr2 = &data;
    data = NULL;
    {
        long long * data = *data_ptr1;
        /* FIX: Allocate and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = (long long *)malloc(100*sizeof(long long));
        *data_ptr1 = data;
    }
    {
        long long * data = *data_ptr2;
        {
            long long src[100] = {0}; /* fill with 0's */
            /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
            memmove(data, src, 100*sizeof(long long));
            printLongLongLine(data[0]);
            free(data);
        }
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_dest_long_long_memmove_32_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_dest_long_long_memmove_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_dest_long_long_memmove_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif