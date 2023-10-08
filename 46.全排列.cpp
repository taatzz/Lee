/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 11;
    bool st[N];
    vector<int> tmp;
    vector<vector<int>> res;

    void dfs(vector<int>& num)
    {
        // tmp长度等于数组长度说明已经全部排列完成
        if(tmp.size() >= num.size())
        {
            res.push_back(tmp);
            return;
        }

        for(int i = 0; i < num.size(); i++)
        {
            if(!st[i])
            {
                tmp.push_back(num[i]);
                st[i] = true;
                dfs(num);
                tmp.pop_back();
                st[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);

        return res;
    }
};
// @lc code=end

