public class Prime {
    public static void checkPrime(Integer num) {
        if (num <= 1) {
            System.debug(num + ' is not a prime number.');
            return;
        }

        Boolean isPrime = true;

        for (Integer i = 2; i <= Math.sqrt(num); i++) {
            if (Math.mod(num, i) == 0) { // Correct usage of modulus in Apex
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            System.debug(num + ' is a prime number.');
        } else {
            System.debug(num + ' is not a prime number.');
        }
    }
}