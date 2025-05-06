public class Calculator {
    public static void calculate(Double a, Double b) {
        System.debug('Add: ' + (a + b));
        System.debug('Subtract: ' + (a - b));
        System.debug('Multiply: ' + (a * b));
        System.debug('Divide: ' + (a / b));
        System.debug('Power: ' + Math.pow(a, b));
        System.debug('Square Root of a: ' + Math.sqrt(a));
    }
}