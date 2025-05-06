public class TemperatureConversion {

    // Convert Celsius to Fahrenheit
    public static void convertCelsiusToFahrenheit(Double celsius) {
        Double fahrenheit = (celsius * 9/5) + 32;
        System.debug(celsius + '°C = ' + fahrenheit + '°F');
    }

    // Convert Fahrenheit to Celsius
    public static void convertFahrenheitToCelsius(Double fahrenheit) {
        Double celsius = (fahrenheit - 32) * 5/9;
        System.debug(fahrenheit + '°F = ' + celsius + '°C');
    }
}