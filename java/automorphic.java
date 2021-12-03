
/**
 * Automorphic Number = A number whose square ends in the same digits as the number itself.
 * E.g:// 25, 36, 625 etc.
 */
import java.util.Scanner;

public class automorphic {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int n = sc.nextInt();
        sc.close();
        int copy = n; // store n in a copy variable n = 5
        int square = n * n; // find the square of the number sq = 25
        int count = 1; // count the number of digits
        while (n > 0) {
            count *= 10; // 10 ^ (numbers of digits)
            n /= 10;
        }
        if (square % count == copy) { // check if the square ends with the same digits as the number itself
            System.out.println("The number is automorphic");
        } else {
            System.out.println("The number is not automorphic");
        }
    }
}