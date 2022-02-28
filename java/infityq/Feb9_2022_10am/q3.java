package infityq.Feb9_2022_10am;

import java.util.*;

class solution {

  static int findMinimumAdjacentSwaps(int arr[], int N) {
    boolean[] visited = new boolean[N + 1];
    int minimumSwaps = 0;
    Arrays.fill(visited, false);
    for (int i = 0; i < 2 * N; i++) {
      if (visited[arr[i]] == false) {
        visited[arr[i]] = true;
        int count = 0;
        for (int j = i + 1; j < 2 * N; j++) {
          if (visited[arr[j]] == false)
            count++;
          else if (arr[i] == arr[j])
            minimumSwaps += count;
        }
      }
    }
    return minimumSwaps;
  }

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    String[] s = sc.nextLine().split(",");
    int N = s.length;
    int[] arr = new int[N];
    for (int i = 0; i < s.length; i++) {
      arr[i] = s[i].charAt(0) - 'A';
    }

    N /= 2;

    int swaps = findMinimumAdjacentSwaps(arr, N);
    if (swaps == 0) {
      System.out.println("-1");
    } else {
      System.out.println(swaps);
    }

  }
}