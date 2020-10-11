/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_ncpy_67a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_src.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: ncpy
 *    BadSink : Copy data to string using wcsncpy
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_ncpy_67_struct_type
{
    wchar_t * a;
} CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_ncpy_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_ncpy_67b_bad_sink(CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_ncpy_67_struct_type my_struct);

void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_ncpy_67_bad()
{
    wchar_t * data;
    CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_ncpy_67_struct_type my_struct;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
    wmemset(data, L'A', 100-1); /* fill with L'A's */
    data[100-1] = L'\0'; /* null terminate */
    my_struct.a = data;
    CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_ncpy_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_ncpy_67b_goodG2B_sink(CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_ncpy_67_struct_type my_struct);

static void goodG2B()
{
    wchar_t * data;
    CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_ncpy_67_struct_type my_struct;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    /* FIX: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
    wmemset(data, L'A', 50-1); /* fill with L'A's */
    data[50-1] = L'\0'; /* null terminate */
    my_struct.a = data;
    CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_ncpy_67b_goodG2B_sink(my_struct);
}

void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_ncpy_67_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_ncpy_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_ncpy_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif