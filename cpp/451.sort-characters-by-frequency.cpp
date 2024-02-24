/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	string frequencySort(string s)
	{
		unordered_map<char, int> my_hash;
		for (auto const &ch : s)
		{
			my_hash[ch]++;
		}

		vector<pair<char, int>> fre;
		for (auto const &it : my_hash)
		{
			fre.push_back({it.first, it.second});
		}

		sort(fre.begin(), fre.end(), [](const pair<char, int> &a, const pair<char, int> &b)
		     { return a.second > b.second; });

		string ans;
		for (auto &it : fre)
		{
			for (int i = 0; i < it.second; ++i)
			{
				ans += it.first;
			}
		}

		return ans;
	}
};
// @lc code=end
