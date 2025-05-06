public class MatrixAddition {
    public static void addMatrices() {
        // Define matrix A
        List<List<Integer>> a = new List<List<Integer>>{
            new List<Integer>{1, 2},
            new List<Integer>{3, 4}
        };

        // Define matrix B
        List<List<Integer>> b = new List<List<Integer>>{
            new List<Integer>{5, 6},
            new List<Integer>{7, 8}
        };

        // Create result matrix
        List<List<Integer>> result = new List<List<Integer>>();
        for (Integer i = 0; i < 2; i++) {
            result.add(new List<Integer>{0, 0});
        }

        // Matrix addition logic
        for (Integer i = 0; i < 2; i++) {
            for (Integer j = 0; j < 2; j++) {
                result[i][j] = a[i][j] + b[i][j];
            }
        }

        // Print result matrix
        System.debug('Matrix Sum:');
        for (List<Integer> row : result) {
            System.debug(row);
        }
    }
}