/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memcpy_66a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_dest.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: memcpy
 *    BadSink : Copy twoints array to data using memcpy
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memcpy_66b_bad_sink(twoints * data_array[]);

void CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memcpy_66_bad()
{
    twoints * data;
    twoints * data_array[5];
    data = NULL;
    /* FLAW: Allocate and point data to a small buffer that is smaller than the large buffer used in the sinks */
    data = (twoints *)malloc(50*sizeof(twoints));
    /* put data in array */
    data_array[2] = data;
    CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memcpy_66b_bad_sink(data_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memcpy_66b_goodG2B_sink(twoints * data_array[]);

static void goodG2B()
{
    twoints * data;
    twoints * data_array[5];
    data = NULL;
    /* FIX: Allocate and point data to a large buffer that is at least as large as the large buffer used in the sink */
    data = (twoints *)malloc(100*sizeof(twoints));
    data_array[2] = data;
    CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memcpy_66b_goodG2B_sink(data_array);
}

void CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memcpy_66_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memcpy_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memcpy_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif