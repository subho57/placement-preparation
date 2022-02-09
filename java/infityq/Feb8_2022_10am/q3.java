package infityq.Feb8_2022_10am;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class q3 {
  static Set<String> hash_Set = new HashSet<>();
  static void Permutation(String str, String ans) {
    if (str.length() == 0) {
      hash_Set.add(ans);
      return;
    }
    for (int i = 0; i < str.length(); i++) {
      char ch = str.charAt(i);
      String ros = str.substring(0, i)
          + str.substring(i + 1);
      Permutation(ros, ans + ch);
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String[] inArr1 = sc.nextLine().split(",");
    String[] inArr2 = sc.nextLine().split(",");
    String inStr1 = sc.nextLine();
    String inStr2 = sc.nextLine();
    sc.close();
    String temp = "";
    for (String s : inArr1) {
      temp += s;
    }
    Permutation(temp, "");
  }
}
