package infityq.Feb8_2022_10am;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class q2 {
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    int inNum = Integer.parseInt(br.readLine());
    int[][] inMatrix = new int[n][n];
    for (int i = 0; i < n; i++) {
      String[] line = br.readLine().split(",");
      int j = 0;
      for (String element: line) {
        inMatrix[i][j++] = Integer.parseInt(element);
      }
    }
    int totalSubMatrix = (inNum < n) ? n/inNum + 1 : n/inNum;
    int minSum = Integer.MAX_VALUE;
    int maxSum = Integer.MIN_VALUE;
    // calculate the sum of elements of kxk submatrix from n x n matrix
    for (int i = 0; i < totalSubMatrix; i++) {
      for (int j = 0; j < totalSubMatrix; j++) {
        int sum = 0;
        for (int k = i; k < inNum + i; k++) {
          for (int l = j; l < inNum + j; l++) {
            // System.out.print(inMatrix[k][l]);
            sum += inMatrix[k][l];
          }
          // System.out.println();
        }
        // System.out.println("sum: " + sum + "\n");
        if (sum < minSum && sum > 0) {
          minSum = sum;
        }
        if (sum > maxSum && sum > 0) {
          maxSum = sum;
        }
      }
    }
    if (minSum == maxSum) {
      System.out.println(minSum);
    } else {
      System.out.println(minSum + ":" + maxSum);
    }
  }
}