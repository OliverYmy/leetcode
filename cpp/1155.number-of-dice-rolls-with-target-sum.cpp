/*
 * @lc app=leetcode.cn id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int numRollsToTarget(int n, int k, int target)
	{
		int MOD = 1e9 + 7;

		// dynamic programming
		vector<vector<int>> dp(n + 1, vector<int>(target + 1));
		dp[0][0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j <= target; ++j)
			{
				for (int x = 1; x <= k; ++x)
				{
					if (j - x >= 0)
					{
						dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
					}
				}
			}
		}
		return dp[n][target];

		// DP optimize
	}
};
// @lc code=end
