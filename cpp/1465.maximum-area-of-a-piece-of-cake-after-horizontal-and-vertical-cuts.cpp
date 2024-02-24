/*
 * @lc app=leetcode.cn id=1465 lang=cpp
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
	{
		int MOD = 1e9 + 7;
		sort(horizontalCuts.begin(), horizontalCuts.end());
		sort(verticalCuts.begin(), verticalCuts.end());

		// tedious solution
		// int max_width = horizontalCuts[0];
		// for(int i = 1; i < horizontalCuts.size(); ++i){
		//     max_width = max(max_width, horizontalCuts[i] - horizontalCuts[i-1]);
		// }
		// max_width = max(max_width, h - horizontalCuts[horizontalCuts.size()-1]);

		// int max_height = verticalCuts[0];
		// for(int i = 1; i < verticalCuts.size(); ++i){
		//     max_height = max(max_height, verticalCuts[i] - verticalCuts[i-1]);
		// }
		// max_height = max(max_height, w - verticalCuts[verticalCuts.size()-1]);

		// return 1LL * (max_width % MOD) * (max_height % MOD) % MOD;

		// simpler solution
		auto calMax = [](vector<int> &arr, int border) -> int
		{
			int res = 0, pre = 0;
			for (int i : arr)
			{
				res = max(res, i - pre);
				pre = i;
			}
			return max(res, border - pre);
		};

		return (long long)calMax(horizontalCuts, h) * calMax(verticalCuts, w) % MOD;
	}
};
// @lc code=end
