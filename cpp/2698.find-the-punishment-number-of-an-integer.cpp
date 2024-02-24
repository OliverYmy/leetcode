/*
 * @lc app=leetcode.cn id=2698 lang=cpp
 *
 * [2698] Find the Punishment Number of an Integer
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

inline bool check(int t, int x)
{
	if (t == x)
		return true;

	int b = 10;
	while (t >= b && x - t % b >= 0)
	{
		if (check(t / b, x - t % b))
			return true;
		b *= 10;
	}
	return false;
}

// initialization during compile time, more detail see
// https://zhuanlan.zhihu.com/p/250238866

int f[1010];
int _ = []()
{
	for (int i = 1; i < 1010; ++i)
	{
		f[i] = f[i - 1];
		if (check(i * i, i))
			f[i] += i * i;
	}
	return 0;
}();

class Solution
{
public:
	int punishmentNumber(int n)
	{

		return f[n];

		// Normal iteration
		// int ans = 0;
		// for (int i = 1; i <= n; ++i) {
		//     if (check(i * i, i))
		//         ans += i * i;
		// }
		// return ans;
	}

	// Normal iteration
	// bool check(int t, int x) {
	//     if (t == x)
	//         return true;

	//     int b = 10;
	//     while (t >= b && x - t % b >= 0) {
	//         if (check(t / b, x - t % b))
	//             return true;
	//         b *= 10;
	//     }
	//     return false;
	// }
};

// @lc code=end
