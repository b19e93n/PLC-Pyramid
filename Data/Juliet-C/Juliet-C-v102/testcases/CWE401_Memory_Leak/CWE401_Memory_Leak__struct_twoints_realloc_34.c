/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__struct_twoints_realloc_34.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef union
{
    struct _twoints * a;
    struct _twoints * b;
} CWE401_Memory_Leak__struct_twoints_realloc_34_union_type;

#ifndef OMITBAD

void CWE401_Memory_Leak__struct_twoints_realloc_34_bad()
{
    struct _twoints * data;
    CWE401_Memory_Leak__struct_twoints_realloc_34_union_type my_union;
    data = NULL;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (struct _twoints *)realloc(data, 100*sizeof(struct _twoints));
    /* Initialize and make use of data */
    data[0].a = 0;
    data[0].b = 0;
    printStructLine((twoints *)&data[0]);
    my_union.a = data;
    {
        struct _twoints * data = my_union.b;
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    struct _twoints * data;
    CWE401_Memory_Leak__struct_twoints_realloc_34_union_type my_union;
    data = NULL;
    {
        /* FIX: Use memory allocated on the stack */
        struct _twoints data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        data[0].a = 0;
        data[0].b = 0;
        printStructLine((twoints *)&data[0]);
    }
    my_union.a = data;
    {
        struct _twoints * data = my_union.b;
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    struct _twoints * data;
    CWE401_Memory_Leak__struct_twoints_realloc_34_union_type my_union;
    data = NULL;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (struct _twoints *)realloc(data, 100*sizeof(struct _twoints));
    /* Initialize and make use of data */
    data[0].a = 0;
    data[0].b = 0;
    printStructLine((twoints *)&data[0]);
    my_union.a = data;
    {
        struct _twoints * data = my_union.b;
        /* FIX: Deallocate memory */
        free(data);
    }
}

void CWE401_Memory_Leak__struct_twoints_realloc_34_good()
{
    goodG2B();
    goodB2G();
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
    CWE401_Memory_Leak__struct_twoints_realloc_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__struct_twoints_realloc_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif