/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__empty_for_01.java
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-01.tmpl.java
*/
/*
* @description
* CWE: 398 Indicator of Poor Code Quality
* Sinks: empty_for
*    GoodSink: For statement contains code
*    BadSink : An empty for statement has no effect
* Flow Variant: 01 Baseline
*
* */





public class CWE398_Poor_Code_Quality__empty_for_01 extends AbstractTestCase
{
    public void bad() throws Throwable
    {

        /* FLAW: An empty for statement has no effect */
        for (int i = 0; i < 10; i++)
        {
        }

        IO.writeLine("Hello from bad()");

    }

    public void good() throws Throwable
    {
        good1();
    }

    private void good1() throws Throwable
    {

        /* FIX: Do not include an empty for statement */
        for (int i = 0; i < 10; i++)
        {
            IO.writeLine("Inside the for statement");
        }

        IO.writeLine("Hello from good()");

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
