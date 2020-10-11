/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__new_char_memmove_32.cpp
Label Definition File: CWE127_Buffer_Underread__new.label.xml
Template File: sources-sink-32.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE127_Buffer_Underread__new_char_memmove_32
{

#ifndef OMITBAD

void bad()
{
    char * data;
    char * *data_ptr1 = &data;
    char * *data_ptr2 = &data;
    data = NULL;
    {
        char * data = *data_ptr1;
        {
            char * data_buf = new char[100];
            memset(data_buf, 'A', 100-1);
            data_buf[100-1] = '\0';
            /* FLAW: Set data pointer to before the allocated memory buffer */
            data = data_buf - 8;
        }
        *data_ptr1 = data;
    }
    {
        char * data = *data_ptr2;
        {
            char dest[100];
            memset(dest, 'C', 100-1); /* fill with 'C's */
            dest[100-1] = '\0'; /* null terminate */
            /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
            memmove(dest, data, 100*sizeof(char));
            /* Ensure null termination */
            dest[100-1] = '\0';
            printLine(dest);
            /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
               returned by new [] so can't safely call delete [] on it */
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char * *data_ptr1 = &data;
    char * *data_ptr2 = &data;
    data = NULL;
    {
        char * data = *data_ptr1;
        {
            char * data_buf = new char[100];
            memset(data_buf, 'A', 100-1);
            data_buf[100-1] = '\0';
            /* FIX: Set data pointer to the allocated memory buffer */
            data = data_buf;
        }
        *data_ptr1 = data;
    }
    {
        char * data = *data_ptr2;
        {
            char dest[100];
            memset(dest, 'C', 100-1); /* fill with 'C's */
            dest[100-1] = '\0'; /* null terminate */
            /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
            memmove(dest, data, 100*sizeof(char));
            /* Ensure null termination */
            dest[100-1] = '\0';
            printLine(dest);
            /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
               returned by new [] so can't safely call delete [] on it */
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

using namespace CWE127_Buffer_Underread__new_char_memmove_32; // so that we can use good and bad easily

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