public class FibonaciiSeries {
    public static void generateFibonacci(Integer n) {
        Integer a = 0, b = 1, c;
        System.debug(a);
        System.debug(b);
        for (Integer i = 2; i < n; i++) {
            c = a + b;
            System.debug(c);
            a = b;
            b = c;
        }
    }
}