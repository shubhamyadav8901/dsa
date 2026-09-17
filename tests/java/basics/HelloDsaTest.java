public class HelloDsaTest {
    public static void main(String[] args) {
        Check.eq(HelloDsa.sumToNLoop(0), 0L, "sumToNLoop(0)");
        Check.eq(HelloDsa.sumToNLoop(1), 1L, "sumToNLoop(1)");
        Check.eq(HelloDsa.sumToNLoop(10), 55L, "sumToNLoop(10)");

        Check.eq(HelloDsa.sumToNFormula(0), 0L, "sumToNFormula(0)");
        Check.eq(HelloDsa.sumToNFormula(1), 1L, "sumToNFormula(1)");
        Check.eq(HelloDsa.sumToNFormula(10), 55L, "sumToNFormula(10)");

        // The two implementations must agree everywhere, not just on nice inputs.
        for (int n = 0; n <= 200; n++) {
            Check.eq(HelloDsa.sumToNLoop(n), HelloDsa.sumToNFormula(n), "agree at n=" + n);
        }

        System.exit(Check.report("HelloDsaTest"));
    }
}
