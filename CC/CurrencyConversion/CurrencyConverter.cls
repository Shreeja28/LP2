public class CurrencyConverter {

    // === INR to Other Currencies ===
    public static void convertINRtoUSD(Double inr) {
        Double rate = 83.0;
        Double usd = inr / rate;
        System.debug(inr + ' INR = ' + usd + ' USD');
    }

    public static void convertINRtoEUR(Double inr) {
        Double rate = 90.0;
        Double eur = inr / rate;
        System.debug(inr + ' INR = ' + eur + ' EUR');
    }

    public static void convertINRtoGBP(Double inr) {
        Double rate = 101.0;
        Double gbp = inr / rate;
        System.debug(inr + ' INR = ' + gbp + ' GBP');
    }

    public static void convertINRtoJPY(Double inr) {
        Double rate = 11.2;
        Double jpy = inr / rate;
        System.debug(inr + ' INR = ' + jpy + ' JPY');
    }

    public static void convertINRtoAUD(Double inr) {
        Double rate = 55.0;
        Double aud = inr / rate;
        System.debug(inr + ' INR = ' + aud + ' AUD');
    }

    // === Other Currencies to INR ===
    public static void convertUSDtoINR(Double usd) {
        Double rate = 83.0;
        Double inr = usd * rate;
        System.debug(usd + ' USD = ' + inr + ' INR');
    }

    public static void convertEURtoINR(Double eur) {
        Double rate = 90.0;
        Double inr = eur * rate;
        System.debug(eur + ' EUR = ' + inr + ' INR');
    }

    public static void convertGBPtoINR(Double gbp) {
        Double rate = 101.0;
        Double inr = gbp * rate;
        System.debug(gbp + ' GBP = ' + inr + ' INR');
    }

    public static void convertJPYtoINR(Double jpy) {
        Double rate = 11.2;
        Double inr = jpy * rate;
        System.debug(jpy + ' JPY = ' + inr + ' INR');
    }

    public static void convertAUDtoINR(Double aud) {
        Double rate = 55.0;
        Double inr = aud * rate;
        System.debug(aud + ' AUD = ' + inr + ' INR');
    }
}