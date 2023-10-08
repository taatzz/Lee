/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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

    void dfs(int start, int sum, vector<int>& cand, int target)
    {
        if(sum >= target)
        {
            if(sum == target)
                res.push_back(tmp);
            return;
        }

        for(int i = start; i < cand.size(); i++)
        {
            if(i > start && cand[i] == cand[i - 1])
                continue;
            sum += cand[i];
            tmp.push_back(cand[i]);
            dfs(i + 1, sum, cand, target);
            sum -= cand[i];
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, 0, candidates, target);

        return res;
    }
};
// @lc code=end

