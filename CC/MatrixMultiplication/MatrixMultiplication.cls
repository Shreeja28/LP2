public class MatrixMultiplication {
    public static void multiplyMatrices() {
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

        // Create result matrix initialized with 0
        List<List<Integer>> result = new List<List<Integer>>();
        for (Integer i = 0; i < 2; i++) {
            result.add(new List<Integer>{0, 0});
        }

        // Matrix multiplication logic
        for (Integer i = 0; i < 2; i++) {
            for (Integer j = 0; j < 2; j++) {
                Integer sum = 0;
                for (Integer k = 0; k < 2; k++) {
                    sum += a[i][k] * b[k][j];
                }
                result[i][j] = sum;
            }
        }

        // Print result matrix
        System.debug('Matrix Product:');
        for (List<Integer> row : result) {
            System.debug(row);
        }
    }
}