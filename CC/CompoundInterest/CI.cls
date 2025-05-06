public class CI {
    public static void calculate(Double principal, Double rate, Integer timesPerYear, Double years) {
        Double r = rate / 100; // Convert rate to decimal
        Double amount = principal * Math.pow(1 + (r / timesPerYear), timesPerYear * years);
        Double compoundInterest = amount - principal;

        System.debug('Principal: ' + principal);
        System.debug('Rate: ' + rate + '%');
        System.debug('Time: ' + years + ' years');
        System.debug('Compound Interest: ' + compoundInterest);
        System.debug('Total Amount: ' + amount);
    }
}