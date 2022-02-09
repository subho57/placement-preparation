package infityq.Feb8_2022_10am;

import java.util.Scanner;

public class q4 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String[] inArr = sc.nextLine().split(",");
    sc.close();
    double sum = 0.0;
    for (int i = 0; i < inArr.length; i++) {
      if (inArr[i].contains("6")) {
        inArr[i] = inArr[i].replace("6", "9");
        inArr[i] = new StringBuffer(inArr[i]).reverse().toString();
      }
      sum += Integer.parseInt(inArr[i]);
    }
    double outnum = Math.round(sum/inArr.length * 100.0) / 100.0;
    System.out.println(outnum);
  }
  
}
