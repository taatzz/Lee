/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> res;

    /// @brief 
    /// @param x 当前可以选择的位置
    /// @param sum 选择数字的总和
    /// @param cand 选择数组
    /// @param target 目标总和
    void dfs(int x, int sum, vector<int>& cand, int target)
    {
        if(sum >= target)
        {
            if(sum == target)
                res.push_back(tmp);
            return;
        }

        for(int i = x; i < cand.size(); i++)
        {
            sum += cand[i];
            tmp.push_back(cand[i]);
            // 可以重复选择自己本身递归i本身
            dfs(i, sum, cand, target);
            sum -= cand[i]; // 恢复现场
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, 0, candidates, target);

        return res;
    }
};
// @lc code=end

