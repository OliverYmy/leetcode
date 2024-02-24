/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int, int> my_hash;
		int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			int tmp = target - nums[i];
			if (my_hash.count(tmp))
			{
				return {my_hash[tmp], i};
			}
			else
			{
				my_hash[nums[i]] = i;
			}
		}
		return {-1, -1};
	}
};
// @lc code=end
