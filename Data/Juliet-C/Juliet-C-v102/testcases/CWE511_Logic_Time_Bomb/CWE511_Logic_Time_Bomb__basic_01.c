/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE511_Logic_Time_Bomb__basic_01.c
Label Definition File: CWE511_Logic_Time_Bomb__basic.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 511 Logic Time Bomb
 * Sinks:
 *    GoodSink: After a certain date, do something harmless
 *    BadSink : After a certain date, do something bad
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <time.h>

#define TIME_CHECK ((time_t)1199163600) /* Jan 1, 2008 12:00:00 AM */

#ifdef _WIN32
# define UNLINK _unlink
#else
# define UNLINK unlink
#endif

#ifndef OMITBAD

void CWE511_Logic_Time_Bomb__basic_01_bad()
{
    {
        time_t time_val;
        /* FLAW: After a certain date, delete a file */
        time(&time_val);
        if (time_val > TIME_CHECK)
        {
            UNLINK("important_file.txt");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        time_t time_val;
        /* FLAW: After a certain date, print to the console */
        time(&time_val);
        if (time_val > TIME_CHECK)
        {
            printLine("Happy New Year!");
        }
    }
}

void CWE511_Logic_Time_Bomb__basic_01_good()
{
    good1();
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
    CWE511_Logic_Time_Bomb__basic_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE511_Logic_Time_Bomb__basic_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif