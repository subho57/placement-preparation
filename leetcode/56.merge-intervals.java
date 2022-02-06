import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;

/*
 * @lc app=leetcode id=56 lang=java
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
    public int[][] merge(int[][] intervals) {
      HashMap<Integer, Boolean> hMap = new HashMap<>();
      ArrayList<int[]> output = new ArrayList<>();
      for (int[] range : intervals) {
        for (int point = range[0]; point <= range[1]; point++) {
          boolean isBreak = (point == range[0] || point == range[1]) ? true : false;
          hMap.putIfAbsent(point, isBreak);
        }
      }
      int min = Collections.min(hMap.keySet());
      int max = Collections.max(hMap.keySet());

      for (int init = min, curr = min; curr <= max; curr++) {
        if (curr == max || (hMap.containsKey(curr) && (!hMap.containsKey(curr + 1) || hMap.get(curr)))) {
          output.add(new int[] {init, curr});
          init = curr;
        } else if (!hMap.containsKey(curr)) {
          init = curr + 1;
        }
      }
      return output.toArray(int[][]::new);
    }
}
// @lc code=end

