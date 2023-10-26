/*
 * @lc app=leetcode.cn id=2910 lang=cpp
 *
 * [2910] Minimum Number of Groups to Create a Valid Assignment
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool is_split(int a, int b) {
        for (int i = a / b; i >= 0; --i) {
            if ((a - i * b) % (b + 1) == 0)
                return true;
        }
        return false;
    }

    int minGroupsForValidAssignment(vector<int> &nums) {
        int n = nums.size();

        // get frequency
        unordered_map<int, int> my_map;
        for (int i = 0; i < n; ++i)
            my_map[nums[i]]++;
        vector<int> fre;
        for (auto &it : my_map)
            fre.push_back(it.second);

        int ans = n;
        int k = *min_element(fre.begin(), fre.end());

        for (; k >= 1; --k) {
            bool isSplit = true;
            for (auto &num : fre) {
                if (!is_split(num, k))
                    isSplit = false;
            }

            if (isSplit) {
                int tmp = 0;
                for (auto &num : fre)
                    tmp += (num + k) / (k + 1);
                return tmp;
            }
        }

        return ans;
    }
};
// @lc code=end
