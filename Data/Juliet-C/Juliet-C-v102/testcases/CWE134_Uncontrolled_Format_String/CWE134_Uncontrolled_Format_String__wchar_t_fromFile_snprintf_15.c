/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_fromFile_snprintf_15.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromFile Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: snprintf
 *    GoodSink: snwprintf with "%s" as the third argument and data as the fourth
 *    BadSink : snwprintf with data as the third argument
 * Flow Variant: 15 Control flow: switch(6) and switch(7)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifdef _WIN32
# define SNPRINTF _snwprintf
#else /* NOT _WIN32 */
# define SNPRINTF snwprintf
#endif

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__wchar_t_fromFile_snprintf_15_bad()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    switch(6)
    {
    case 6:
    {
        /* Read input from a file */
        size_t data_len = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if(100-data_len > 1)
        {
            pFile = FOPEN(L"C:\\temp\\file.txt", L"r");
            if (pFile != NULL)
            {
                fgetws(data+data_len, (int)(100-data_len), pFile);
                fclose(pFile);
            }
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
        break;
    }
    switch(7)
    {
    case 7:
    {
        wchar_t dest[100] = L"";
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printWLine(dest);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        wchar_t dest[100] = L"";
        /* FIX: Specify the format disallowing a format string vulnerability */
        SNPRINTF(dest, 100-1, L"%s", data);
        printWLine(dest);
    }
    break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second switch to switch(8) */
static void goodB2G1()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    switch(6)
    {
    case 6:
    {
        /* Read input from a file */
        size_t data_len = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if(100-data_len > 1)
        {
            pFile = FOPEN(L"C:\\temp\\file.txt", L"r");
            if (pFile != NULL)
            {
                fgetws(data+data_len, (int)(100-data_len), pFile);
                fclose(pFile);
            }
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
        break;
    }
    switch(8)
    {
    case 7:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        wchar_t dest[100] = L"";
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printWLine(dest);
    }
    break;
    default:
    {
        wchar_t dest[100] = L"";
        /* FIX: Specify the format disallowing a format string vulnerability */
        SNPRINTF(dest, 100-1, L"%s", data);
        printWLine(dest);
    }
    break;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second switch */
static void goodB2G2()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    switch(6)
    {
    case 6:
    {
        /* Read input from a file */
        size_t data_len = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if(100-data_len > 1)
        {
            pFile = FOPEN(L"C:\\temp\\file.txt", L"r");
            if (pFile != NULL)
            {
                fgetws(data+data_len, (int)(100-data_len), pFile);
                fclose(pFile);
            }
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
        break;
    }
    switch(7)
    {
    case 7:
    {
        wchar_t dest[100] = L"";
        /* FIX: Specify the format disallowing a format string vulnerability */
        SNPRINTF(dest, 100-1, L"%s", data);
        printWLine(dest);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        wchar_t dest[100] = L"";
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printWLine(dest);
    }
    break;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first switch to switch(5) */
static void goodG2B1()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* Read input from a file */
        size_t data_len = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if(100-data_len > 1)
        {
            pFile = FOPEN(L"C:\\temp\\file.txt", L"r");
            if (pFile != NULL)
            {
                fgetws(data+data_len, (int)(100-data_len), pFile);
                fclose(pFile);
            }
        }
    }
    break;
    default:
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
        break;
    }
    switch(7)
    {
    case 7:
    {
        wchar_t dest[100] = L"";
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printWLine(dest);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        wchar_t dest[100] = L"";
        /* FIX: Specify the format disallowing a format string vulnerability */
        SNPRINTF(dest, 100-1, L"%s", data);
        printWLine(dest);
    }
    break;
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first switch */
static void goodG2B2()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    switch(6)
    {
    case 6:
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* Read input from a file */
        size_t data_len = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if(100-data_len > 1)
        {
            pFile = FOPEN(L"C:\\temp\\file.txt", L"r");
            if (pFile != NULL)
            {
                fgetws(data+data_len, (int)(100-data_len), pFile);
                fclose(pFile);
            }
        }
    }
    break;
    }
    switch(7)
    {
    case 7:
    {
        wchar_t dest[100] = L"";
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printWLine(dest);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        wchar_t dest[100] = L"";
        /* FIX: Specify the format disallowing a format string vulnerability */
        SNPRINTF(dest, 100-1, L"%s", data);
        printWLine(dest);
    }
    break;
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_fromFile_snprintf_15_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE134_Uncontrolled_Format_String__wchar_t_fromFile_snprintf_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__wchar_t_fromFile_snprintf_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif