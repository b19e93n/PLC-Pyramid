/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__new_twoints_array_partial_init_63b.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__new.label.xml
Template File: sources-sinks-63b.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: partial_init Initialize part, but not all of the array
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE457_Use_of_Uninitialized_Variable__new_twoints_array_partial_init_63
{

#ifndef OMITBAD

void bad_sink(twoints * * data_ptr)
{
    twoints * data = *data_ptr;
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
    /* deallocate the memory */
    delete [] data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink(twoints * * data_ptr)
{
    twoints * data = *data_ptr;
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
    /* deallocate the memory */
    delete [] data;
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink(twoints * * data_ptr)
{
    twoints * data = *data_ptr;
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
    }
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
    /* deallocate the memory */
    delete [] data;
}

#endif /* OMITGOOD */

} // close namespace