import java.util.Arrays;
import java.util.Objects;

/**
 * The Java twin of tests/cpp/dsa_test.hpp - a tiny check helper, no JUnit.
 *
 * Usage in a test file (tests/java/&lt;topic&gt;/&lt;Name&gt;Test.java):
 *
 *     public class TwoSumTest {
 *         public static void main(String[] args) {
 *             Check.eq(TwoSum.twoSum(new int[]{2, 7, 11, 15}, 9), new int[]{0, 1}, "basic case");
 *             System.exit(Check.report("TwoSumTest"));
 *         }
 *     }
 */
public final class Check {
    private static int checksRun = 0;
    private static int checksFailed = 0;

    private Check() {}

    public static void eq(Object actual, Object expected, String what) {
        checksRun++;
        if (Objects.deepEquals(actual, expected))
            return;
        checksFailed++;
        System.out.println("  FAIL  " + what);
        System.out.println("        expected: " + show(expected));
        System.out.println("        actual:   " + show(actual));
    }

    public static void isTrue(boolean condition, String what) {
        eq(condition, true, what);
    }

    public static void isFalse(boolean condition, String what) {
        eq(condition, false, what);
    }

    /** Returns the process exit code: 0 when everything passed. */
    public static int report(String suite) {
        if (checksFailed == 0) {
            System.out.println("  PASS  " + suite + "  (" + checksRun + " checks)");
            return 0;
        }
        System.out.println(
            "  FAILED " + suite + "  (" + checksFailed + " of " + checksRun + " checks failed)");
        return 1;
    }

    private static String show(Object value) {
        if (value == null)
            return "null";
        if (value instanceof int[] a)
            return Arrays.toString(a);
        if (value instanceof long[] a)
            return Arrays.toString(a);
        if (value instanceof double[] a)
            return Arrays.toString(a);
        if (value instanceof boolean[] a)
            return Arrays.toString(a);
        if (value instanceof char[] a)
            return Arrays.toString(a);
        if (value instanceof Object[] a)
            return Arrays.deepToString(a);
        if (value instanceof String s)
            return "\"" + s + "\"";
        return String.valueOf(value);
    }
}
