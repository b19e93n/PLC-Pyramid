/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_listen_socket_fopen_52b.c
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: File name without a period or slash
 * Sink: fopen
 *    BadSink :
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH "c:\\temp\\"
#else
#define BASEPATH "/tmp/"
#endif

#ifdef _WIN32
# include <winsock2.h>
# include <windows.h>
# include <direct.h>
# define PATH_SZ FILENAME_MAX
# pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
# define CLOSE_SOCKET closesocket
#else
# define PATH_SZ PATH_MAX
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define CLOSE_SOCKET close
# define SOCKET int
#endif

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE23_Relative_Path_Traversal__char_listen_socket_fopen_52c_bad_sink(char * data);

void CWE23_Relative_Path_Traversal__char_listen_socket_fopen_52b_bad_sink(char * data)
{
    CWE23_Relative_Path_Traversal__char_listen_socket_fopen_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE23_Relative_Path_Traversal__char_listen_socket_fopen_52c_goodG2B_sink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE23_Relative_Path_Traversal__char_listen_socket_fopen_52b_goodG2B_sink(char * data)
{
    CWE23_Relative_Path_Traversal__char_listen_socket_fopen_52c_goodG2B_sink(data);
}

#endif /* OMITGOOD */