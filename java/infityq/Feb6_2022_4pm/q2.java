package infityq.Feb6_2021_4pm;
/**
 * Consider two non-empty positive integer arrays inarr1 & inarr2 as inputs.
 * Identify & print a 2 x m matrix, outmatrix based on the logic given below:
 * 
 * - Search common integers between inarr1 & inarr2.
 * - Select the smallest integer, m, among the comon integers. If the smallest integer is not a single digit
 *   number, then consecutively add its digits until m becomes a single digit number.
 * - Based on the single digit, m, obtained frmo the above, pick those many largest elements each form 
 *   inarr1 & inarr2.
 * - From outmatrix, in which the first row will contain m largest elements selected from the inarr1 & 
 *   the second row will contain m largest elements selected from the inarr2. Each row will contain elements
 *   in ASCENDING order.
 * - If no common integer exists or smallest common integer value is zero or largest than any of the input
 *   array size, then print "-1"
 * 
 * Sample Input 1:
 * 0,17,61,65,90
 * 5,0,1,4,100
 * 
 * Sample Output 1:
 * -1
 * 
 * Sample Input 2:
 * 101,101,610,447,389
 * 610,4,101,4,101
 * 
 * Sample Output 2:
 * 447,610
 * 101,610
 */
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


    if (common.size() == 0 || Collections.min(common) == 0) {
      System.out.println("-1");
    } else {
      int m = Collections.min(common);
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
