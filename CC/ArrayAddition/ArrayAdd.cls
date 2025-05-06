public class ArrayAddition {
    public static void performAddition() {
        List<Integer> arr1 = new List<Integer>{1, 2, 3};
        List<Integer> arr2 = new List<Integer>{4, 5, 6};
        List<Integer> result = new List<Integer>();

        for (Integer i = 0; i < arr1.size(); i++) {
            result.add(arr1[i] + arr2[i]);
        }

        System.debug('Result Array: ' + result);
    }
}
