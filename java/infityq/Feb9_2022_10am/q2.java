package infityq.Feb9_2022_10am;

import java.util.ArrayList;
import java.util.Scanner;

public class q2 {
  public static int minSwaps(int[] nums) {
    int count = 0;
    for (int i = 0; i < nums.length; i++)
      if (nums[i] == 1)
        count++;
    if (count < 2)
      return 0;
    int[] new_arr = new int[nums.length * 2];
    for (int i = 0; i < new_arr.length; i++) {
      new_arr[i] = nums[i % nums.length];
    }
    int bad = 0;
    for (int i = 0; i < count; i++) {
      if (nums[i] != 1)
        bad++;
    }
    int res = bad;
    for (int i = 0, j = count; j < new_arr.length; i++, j++) {
      if (new_arr[i] != 1)
        bad--;
      if (new_arr[j] != 1)
        bad++;
      res = Math.min(res, bad);
    }
    return res;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String[] inArr = sc.nextLine().split(",");
    sc.close();
    ArrayList<Integer> nums = new ArrayList<Integer>();
    for (int i = 0; i < inArr.length; i++) {
      nums.add(inArr[i].charAt(0) - 'A');
    }
    int outNum = minSwaps(nums.stream().mapToInt(i -> i).toArray());
    outNum = (outNum == 0) ? -1 : outNum;
    System.out.println(outNum);
  }
}