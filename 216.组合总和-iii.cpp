/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
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
    /// @param start 当前开始枚举的数
    /// @param k 枚举数字的个数
    /// @param n 等于n时符合题意
    void dfs(int start, int k, int n, int sum)
    {
        if(sum > n)
            return;
        if(tmp.size() == k) // 全部枚举完后判断
        {
            int sum = 0;
            for(auto i : tmp)
            {
                sum += i;
            }
            if(sum == n)
                res.push_back(tmp);
            return;
        }

        // （剪枝）9 -(k - tmp.size()) + 1 可以枚举的数字个数
        for(int i = start; i <= 9 - (k - tmp.size()) + 1; i++)
        {
            tmp.push_back(i);
            sum += i;
            dfs(i + 1, k, n, sum);
            sum -= i;
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n, 0);

        return res;
    }
};
// @lc code=end

