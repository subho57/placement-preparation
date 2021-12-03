/**
 * S = 1/3! + 2/4! + 3/5! + 4/6! + 5/7! + 6/8! + 7/9! + 8/10! + 9/11! + 10/12!
 * ! = Factorial
 */
public class series1 {
    public static double factorial(int n) {
        double fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }
    public static void main(String[] args) {
        double sum = 0;
        for (int i = 1; i <= 10; i++) {
            sum += i / factorial(i+2);
        }
        System.out.println("Sum of the series = " + sum);
    }
}
