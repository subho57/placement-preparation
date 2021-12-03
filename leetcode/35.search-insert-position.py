#
# @lc app=leetcode id=35 lang=python3
#
# [35] Search Insert Position
#

# @lc code=start
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        try:
            return nums.index(target)
        except(ValueError):
            pastIndex = 0
            for i in nums:
                if i > target:
                    break
                pastIndex += 1
            return pastIndex
# @lc code=end

