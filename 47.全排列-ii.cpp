/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 10;
    bool st[N];
    vector<int> path;
    vector<vector<int>> res;

    void dfs(vector<int>& num, int x)
    {
        if(x >= num.size())
        {
            res.push_back(path);
            return;
        }

        for(int i = 0; i < num.size(); i++)
        {
            if(i > 0 && !st[i - 1] && num[i] == num[i - 1])
                continue;
            if(!st[i])
            {
                path.push_back(num[i]);
                st[x] = true;
                dfs(num, x + 1);
                st[x] = false;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        dfs(nums, 0);

        return res;
    }
};
// @lc code=end

