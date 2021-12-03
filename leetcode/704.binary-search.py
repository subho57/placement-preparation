#
# @lc app=leetcode id=704 lang=python3
#
# [704] Binary Search
#

# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums) - 1
        isFound = False
        while(low <= high):
            mid = low + (high-low)//2
            print(mid)
            if (nums[mid] == target):
                isFound = True
                break
            elif nums[mid] < target:
                low = mid + 1              
            elif nums[mid] > target:
                high = mid - 1
        if isFound:
            return mid
        else:
            return -1     
# @lc code=end

