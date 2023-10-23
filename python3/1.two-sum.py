#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        for i in range(len(nums)):
            if (target - nums[i]) in dic:
                return [dic[target - nums[i]], i]
            else:
                dic[nums[i]] = i
        return [-1, -1]

# @lc code=end
