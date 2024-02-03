/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	vector<string> table = {
	    "",
	    "abc",
	    "def",
	    "ghi",
	    "jkl",
	    "mno",
	    "pqrs",
	    "tuv",
	    "wxyz",
	};
	void dfs(string &digits, int u, string &path, vector<string> &ans)
	{
		if (u == digits.size())
		{
			ans.push_back(path);
			return;
		}
		for (char c : table[digits[u] - '0' - 1])
		{
			path.push_back(c);
			dfs(digits, u + 1, path, ans);
			path.pop_back();
		}
	}
	vector<string> letterCombinations(string digits)
	{
		vector<string> ans;
		if (digits.empty())
			return ans;
		string path;
		dfs(digits, 0, path, ans);
		return ans;
	}
};
// @lc code=end
