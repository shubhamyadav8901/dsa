/**
 * Copy to: tests/java/&lt;topic&gt;/&lt;PascalCaseName&gt;Test.java
 *
 * <p>The runner strips the trailing "Test" to find the solution file, so
 * FooTest.java compiles against java/&lt;topic&gt;/Foo.java automatically.
 *
 * <p>Run with: make test L=java T=&lt;topic&gt;
 */
public class SolutionTest {
    public static void main(String[] args) {
        Check.eq(Solution.solve(), 0, "basic case");

        // Always include: smallest input, empty input, and one edge case you
        // expect to get wrong. Arrays compare by value: Check.eq(got, new int[]{0, 1}, "...")

        System.exit(Check.report("SolutionTest"));
    }
}
