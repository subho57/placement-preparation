package infityq.Feb6_2021_4pm;


/**
 * Consider a non-empty input string, instr containing at least two characters which is a combination of
 * lowercase alphabets & digits. Identify and print the output using the below logic:
 * A) Separate the input string into two parts:
 * 1. The first part contains all the lowercase alphabets in sorted order.
 * 2. The second part contains all the digits in sorted order.
 * B) Identify the sort difference ofr sortedaplha and sorteddigits.
 *    - Sorted Sort Difference for a sorted string is the absolute difference between the index of the 
 *      first occurrence of the smallest element & the index of the first occurrence of the largest element
 *      in the original unsorted string, instr.
 * C) From a string by concatenating sortedalpha followed by sort difference of sortedalpha followed by ':'(colon)
 *    followed by sum of digits in instr & the sort difference of sorteddigits.
 * D) If the instr consists of only alphabets or digits, print -1.
 * 
 * NOTE: If the input string contains only alphabets or only digits, print -1.
 * 
 * Input Format:
 * Read the instr from the standard input stream.
 * 
 * Output Format:
 * Print -1 or the output string accordingly on the standard output stream.
 * 
 * Sample Input 1:
 * gt4r22w7e
 * 
 * Sample Output 1:
 * egrtw2:153
 * 
 * Sample Input 2:
 * ace
 * 
 * Sample Output 2:
 * -1
 */

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class q1 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String inputString = sc.nextLine();
    sc.close();

    ArrayList<Character> sortedAlpha = new ArrayList<>();
    ArrayList<Integer> sortedDigits = new ArrayList<>();
    int sof = 0;
    for (int i = 0; i < inputString.length(); i++) {
      char c = inputString.charAt(i);
      if (Character.isDigit(c)) {
        sortedDigits.add(c - '0');
        sof += c - '0';
      } else if (Character.isAlphabetic(c)) {
        sortedAlpha.add(c);
      }
    }

    if (sortedAlpha.size() == 0 || sortedDigits.size() == 0) {
      System.out.println("-1");
    } else {

      Collections.sort(sortedAlpha);
      Collections.sort(sortedDigits);

      int sortDiffAlpha = Math
          .abs(inputString.indexOf(sortedAlpha.get(0)) - inputString.indexOf(sortedAlpha.get(sortedAlpha.size() - 1)));
      int sortDiffDigits = Math
          .abs(inputString.indexOf(sortedDigits.get(0) + '0')
              - inputString.indexOf(sortedDigits.get(sortedDigits.size() - 1) + '0'));

      String outputString = "";
      for (char c : sortedAlpha) {
        outputString += c;
      }

      outputString += sortDiffAlpha + ":" + sof + sortDiffDigits;
      System.out.println(outputString);
    }
  }
}
