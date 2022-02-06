package infityq.Feb6_2021_4pm;

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
