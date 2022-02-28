package infityq.Feb9_2022_10am;

import java.util.ArrayList;
import java.util.Scanner;

public class q1 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String inStr = sc.nextLine();
    String[] inArr = sc.nextLine().split(",");
    sc.close();
    String outStr = "";
    ArrayList<Character> uniqChars = new ArrayList<Character>();
    for (int i = 0; i < inStr.length(); i++) {
      if (uniqChars.contains(inStr.charAt(i)) == false) {
        uniqChars.add(inStr.charAt(i));
      }
    }

    for (char ch : uniqChars) {
      int firstInd = inStr.indexOf(ch);
      ArrayList<Integer> indList = new ArrayList<Integer>();
      for (int i = firstInd + 1; i < inStr.length(); i++) {
        if (inStr.charAt(i) == ch) {
          indList.add(i);
        }
      }
      String str = inArr[firstInd];
      ArrayList<Integer> strInds = new ArrayList<Integer>();
      for (int i = firstInd + 1; i < inArr.length; i++) {
        if (inArr[i].equals(str)) {
          strInds.add(i);
        }
      }
      if (indList.equals(strInds)) {
        outStr += ch;
      } 
    }
    if (outStr.length() == 0) {
      outStr = "NA";
    }
    System.out.println(outStr);
  }
}
