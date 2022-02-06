package infityq.Feb6_2021_4pm;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class q2 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    String[] input1 = sc.nextLine().split(",");
    String[] input2 = sc.nextLine().split(",");

    sc.close();

    ArrayList<Integer> arr1 = new ArrayList<>();
    ArrayList<Integer> arr2 = new ArrayList<>();
    ArrayList<Integer> common = new ArrayList<>();

    for (String s : input1) {
      arr1.add(Integer.parseInt(s));
    }
    for (String s : input2) {
      arr2.add(Integer.parseInt(s));
    }
    
    if (arr1.size() > arr2.size()) {
      for (int i = 0; i < arr2.size(); i++) {
        if (arr1.contains(arr2.get(i))) {
          common.add(arr2.get(i));
        }
      }
    } else {
      for (int i = 0; i < arr1.size(); i++) {
        if (arr2.contains(arr1.get(i))) {
          common.add(arr1.get(i));
        }
      }
    }

    Collections.sort(common);

    if (common.size() == 0 || common.get(0) == 0) {
      System.out.println("-1");
    } else {
      int m = common.get(0);
      while(m > 9) {
        int sof = 0;
        while (m > 0) {
          sof += m % 10;
          m /= 10;
        }
        m = sof;
      }
      Collections.sort(arr1);
      Collections.sort(arr2);

      arr1 = new ArrayList<Integer>(arr1.subList(arr1.size() - m, arr1.size()));
      arr2 = new ArrayList<Integer>(arr2.subList(arr2.size() - m, arr2.size()));

      String output = "";
      for (int i = 0; i < arr1.size(); i++) {
        output += arr1.get(i) + ",";
      }
      output = output.substring(0, output.length() - 1) + "\n";
      for (int i = 0; i < arr2.size(); i++) {
        output += arr2.get(i) + ",";
      }
      output = output.substring(0, output.length() - 1);
      System.out.println(output);

    }
  }
}
