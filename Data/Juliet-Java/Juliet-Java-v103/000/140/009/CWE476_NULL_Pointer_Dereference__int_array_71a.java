/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__int_array_71a.java
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-71a.tmpl.java
*/
/*
 * @description
 * CWE: 476 Null Pointer Dereference
 * BadSource:  Set data to null
 * GoodSource: Set data to a non-null value
 * Sinks:
 *    GoodSink: add check to prevent possibility of null dereference
 *    BadSink : possibility of null dereference
 * Flow Variant: 71 Data flow: data passed as an Object reference argument from one method to another in different classes in the same package
 *
 * */





public class CWE476_NULL_Pointer_Dereference__int_array_71a extends AbstractTestCase
{
    public void bad() throws Throwable
    {
        int [] data;

        /* POTENTIAL FLAW: data is null */
        data = null;

        (new CWE476_NULL_Pointer_Dereference__int_array_71b()).badSink((Object)data  );
    }

    public void good() throws Throwable
    {
        goodG2B();
        goodB2G();
    }

    /* goodG2B() - use goodsource and badsink */
    private void goodG2B() throws Throwable
    {
        int [] data;

        /* FIX: hardcode data to non-null */
        data = new int[5];

        (new CWE476_NULL_Pointer_Dereference__int_array_71b()).goodG2BSink((Object)data  );
    }

    /* goodB2G() - use badsource and goodsink */
    private void goodB2G() throws Throwable
    {
        int [] data;

        /* POTENTIAL FLAW: data is null */
        data = null;

        (new CWE476_NULL_Pointer_Dereference__int_array_71b()).goodB2GSink((Object)data  );
    }

    /* Below is the main(). It is only used when building this testcase on
     * its own for testing or for building a binary to use in testing binary
     * analysis tools. It is not used when compiling all the testcases as one
     * application, which is how source code analysis tools are tested.
     */
    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}