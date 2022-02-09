package infityq.Feb8_2022_10am;

import java.util.Scanner;

public class q1 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String[] inputString = sc.nextLine().split(",");
    sc.close();
    int n = inputString.length;
    int[] inArr = new int[n];
    for (int i = 0; i < n; i++) {
      inArr[i] = Integer.parseInt(inputString[i]);
    }
    if (n == 1)
      System.out.println(inArr[0]);
    else {
      int sum = 0;
      for (int i = 0; i < n; i++) {
        sum += inArr[i];
      }
      int curr_max = inArr[0], max_so_far = inArr[0],
          curr_min = inArr[0], min_so_far = inArr[0];

      for (int i = 1; i < n; i++) {
        curr_max = Math.max(curr_max + inArr[i], inArr[i]);
        max_so_far = Math.max(max_so_far, curr_max);
        curr_min = Math.min(curr_min + inArr[i], inArr[i]);
        min_so_far = Math.min(min_so_far, curr_min);
      }
      if (min_so_far == sum) {
        System.out.println(max_so_far);
      } else {
        System.out.println(Math.max(max_so_far, sum - min_so_far));
      }
    }
  }
}
