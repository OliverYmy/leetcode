/*
 * @lc app=leetcode.cn id=1817 lang=cpp
 *
 * [1817] Finding the Users Active Minutes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k) {
        unordered_map<int, unordered_set<int>> my_hash;
        for (auto const &log : logs) {
            int id = log[0], t = log[1];
            my_hash[id].insert(t);
        }

        vector<int> ans(k, 0);
        for (auto const &it : my_hash) {
            ans[it.second.size() - 1]++;
        }

        return ans;
    }
};
// @lc code=end
