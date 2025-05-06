public class Area {
    public static void calculateArea(Integer radius, Integer side, Integer length, Integer breadth) {
        Double circle = Math.PI * Math.pow(radius, 2);
        Double square = Double.valueOf(side) * side;
        Double rectangle = Double.valueOf(length) * breadth;

        System.debug('Circle Area: ' + circle);
        System.debug('Square Area: ' + square);
        System.debug('Rectangle Area: ' + rectangle);
    }
}
