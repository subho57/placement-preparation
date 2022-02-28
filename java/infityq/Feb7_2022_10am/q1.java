package infityq.Feb7_2021_10am;

import java.util.Scanner;

public class q1 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    String[] inarr = sc.nextLine().split(",");
    int innum = sc.nextInt();

    sc.close();

    int outnum = 999999999;

    for (int i = 0; i < inarr.length - innum + 1; i++) {
      int maxsum = 0;
      for (int j = 0; j < innum; j++) {
        maxsum += Integer.parseInt(inarr[i + j]);
      }
      outnum = Math.min(outnum, maxsum);
    }

    System.out.println(outnum);



  }
}
