/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> res;

    void dfs(vector<int>& num, int start, int last)
    {
        if(start == num.size())
        {
            if(tmp.size() >= 2)
                res.push_back(tmp);
            return;
        }

        if(num[start] >= last)
        {
            tmp.push_back(num[start]);
            dfs(num, start + 1, num[start]);
            tmp.pop_back();
        }
        if(num[start] != last)
            dfs(num, start + 1, last);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0, INT_MIN);

        return res;
    }
};
// @lc code=end

