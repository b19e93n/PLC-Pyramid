/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__fgets_memcpy_32.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Positive integer
 * Sink: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

/* Must be at least 8 for atoi() to work properly */
#define CHAR_ARRAY_SIZE 8

#ifndef OMITBAD

void CWE194_Unexpected_Sign_Extension__fgets_memcpy_32_bad()
{
    short data;
    short *data_ptr1 = &data;
    short *data_ptr2 = &data;
    /* Initialize data */
    data = 0;
    {
        short data = *data_ptr1;
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            /* POTENTIAL FLAW: Use a value input from the console using fgets() */
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to short */
            data = (short)atoi(input_buf);
        }
        *data_ptr1 = data;
    }
    {
        short data = *data_ptr2;
        {
            char src[100];
            char dest[100] = "";
            memset(src, 'A', 100-1);
            src[100-1] = '\0';
            if (data < 100)
            {
                /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
                 * the sign extension could result in a very large number */
                memcpy(dest, src, data);
                dest[data] = '\0'; /* NULL terminate */
            }
            printLine(dest);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    short data;
    short *data_ptr1 = &data;
    short *data_ptr2 = &data;
    /* Initialize data */
    data = 0;
    {
        short data = *data_ptr1;
        /* FIX: Use a positive integer less than &InitialDataSize&*/
        data = 100-1;
        *data_ptr1 = data;
    }
    {
        short data = *data_ptr2;
        {
            char src[100];
            char dest[100] = "";
            memset(src, 'A', 100-1);
            src[100-1] = '\0';
            if (data < 100)
            {
                /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
                 * the sign extension could result in a very large number */
                memcpy(dest, src, data);
                dest[data] = '\0'; /* NULL terminate */
            }
            printLine(dest);
        }
    }
}

void CWE194_Unexpected_Sign_Extension__fgets_memcpy_32_good()
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
    CWE194_Unexpected_Sign_Extension__fgets_memcpy_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE194_Unexpected_Sign_Extension__fgets_memcpy_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif