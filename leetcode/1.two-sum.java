/*
 * @lc app=leetcode id=1 lang=java
 *
 * [1] Two Sum
 */

// @lc code=start
import java.util.HashMap;
import java.util.Map;
class Solution {
    public int[] twoSum(int[] nums, int target)
	{
		int[] result = {-1, -1};
		Map<Integer, Integer> map = new HashMap<>();
		// <Values, Index>

		for (int i = 0; i < nums.length; i++)
		{
			int complement = target - nums[i];
			if (map.containsKey(complement))
			{
				return new int[] { map.get(complement), i };
			}
			map.put(nums[i], i);
		}
		return new int[] {0, 1};

    }
}
// @lc code=end

