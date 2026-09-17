/**
 * HelloDsa.java - the shape every Java solution file in this repo follows.
 *
 * <p>1. Solution methods are {@code public static} on a class named after the file.
 * 2. A playground {@code main} sits at the bottom;
 *    {@code make run FILE=java/basics/HelloDsa.java} runs it.
 *    The test class has its own {@code main}, so this one is simply never called.
 */
public class HelloDsa {

    /** Adds 1 + 2 + ... + n one step at a time. */
    public static long sumToNLoop(int n) {
        long total = 0;
        for (int i = 1; i <= n; i++) {
            total += i;
        }
        return total;
    }

    /** Same answer, computed in a fixed number of operations. */
    public static long sumToNFormula(int n) {
        return (long) n * (n + 1) / 2;
    }

    public static void main(String[] args) {
        int n = 10;
        System.out.println("sumToNLoop(" + n + ")    = " + sumToNLoop(n));
        System.out.println("sumToNFormula(" + n + ") = " + sumToNFormula(n));
        System.out.println();
        System.out.println("Both print the same number. They do not do the same amount of work.");
    }
}
