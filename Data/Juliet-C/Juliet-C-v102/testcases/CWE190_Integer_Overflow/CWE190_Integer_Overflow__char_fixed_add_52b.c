/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_fixed_add_52b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks: add
 *    GoodSink: Ensure there is no overflow before performing the addition
 *    BadSink : Add 1 to data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__char_fixed_add_52c_bad_sink(char data);

void CWE190_Integer_Overflow__char_fixed_add_52b_bad_sink(char data)
{
    CWE190_Integer_Overflow__char_fixed_add_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__char_fixed_add_52c_goodG2B_sink(char data);

void CWE190_Integer_Overflow__char_fixed_add_52b_goodG2B_sink(char data)
{
    CWE190_Integer_Overflow__char_fixed_add_52c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__char_fixed_add_52c_goodB2G_sink(char data);

void CWE190_Integer_Overflow__char_fixed_add_52b_goodB2G_sink(char data)
{
    CWE190_Integer_Overflow__char_fixed_add_52c_goodB2G_sink(data);
}

#endif /* OMITGOOD */