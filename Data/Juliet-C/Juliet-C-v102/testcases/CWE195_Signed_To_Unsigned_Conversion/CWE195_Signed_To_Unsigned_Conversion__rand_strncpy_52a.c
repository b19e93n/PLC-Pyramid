/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_To_Unsigned_Conversion__rand_strncpy_52a.c
Label Definition File: CWE195_Signed_To_Unsigned_Conversion.label.xml
Template File: sources-sink-52a.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Positive integer
 * Sink: strncpy
 *    BadSink : Copy strings using strncpy() with the length of data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE195_Signed_To_Unsigned_Conversion__rand_strncpy_52b_bad_sink(int data);

void CWE195_Signed_To_Unsigned_Conversion__rand_strncpy_52_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    data = RAND32();
    CWE195_Signed_To_Unsigned_Conversion__rand_strncpy_52b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE195_Signed_To_Unsigned_Conversion__rand_strncpy_52b_goodG2B_sink(int data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    CWE195_Signed_To_Unsigned_Conversion__rand_strncpy_52b_goodG2B_sink(data);
}

void CWE195_Signed_To_Unsigned_Conversion__rand_strncpy_52_good()
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
    CWE195_Signed_To_Unsigned_Conversion__rand_strncpy_52_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE195_Signed_To_Unsigned_Conversion__rand_strncpy_52_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif