/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_Environment_54d.c
Label Definition File: CWE761_Free_Pointer_Not_At_Start_Of_Buffer.label.xml
Template File: source-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer Not At Start of Buffer
 * BadSource: Environment Read input from an environment variable
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SEARCH_CHAR 'S'
#define BAD_SRC_FIXED "Fixed String" /* MAINTENANCE NOTE: This string must contain the SEARCH_CHAR */

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
# define GETENV getenv
#else
# define GETENV getenv
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_Environment_54e_bad_sink(char * data);

void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_Environment_54d_bad_sink(char * data)
{
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_Environment_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_Environment_54e_goodB2G_sink(char * data);

void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_Environment_54d_goodB2G_sink(char * data)
{
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_Environment_54e_goodB2G_sink(data);
}

#endif /* OMITGOOD */