
/*
 * @lc app=leetcode id=216 lang=java
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> output = new ArrayList<List<Integer>>();
        if (n > 45 || k > n) {
          return output;
        }
        ArrayList<Integer> temp = new ArrayList<Integer>();
        for (int i = 1; i <= 9; i++) {
          temp.add(i);
        }

        
    }
}
// @lc code=end

