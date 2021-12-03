/**
 * S = 1! + 2! + 4! + 8! + 16!
 */

public class gpFactorialSeries {
    public static double factorial(int n) {
        double fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }
    public static void main(String args[]) {
        
        
    }
}
