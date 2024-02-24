/*
 * @lc app=leetcode.cn id=2520 lang=cpp
 *
 * [2520] Count the Digits That Divide a Number
 */

// @lc code=start
class Solution
{
public:
	int countDigits(int num)
	{
		int ans = 0;
		int n = num;
		while (num)
		{
			int bit = num % 10;
			if (n % bit == 0)
				ans += 1;
			num /= 10;
		}
		return ans;
	}
};
// @lc code=end
