/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 15;
    bool st[N];
    vector<int> tmp;
    vector<vector<int>> res;

    void dfs(vector<int>& num, int start)
    {
        if(start >= num.size())
        {
            tmp.clear();
            for(int i = 0; i < num.size(); i++)
            {
                if(st[i])
                    tmp.push_back(num[i]);
            }
            res.push_back(tmp);
            return;
        }

        st[start] = 0;
        start++;
        dfs(num, start);
        start--;
        st[start] = 0;
        
        // 当前数字与前面的相同，且前面的没有选则跳过
        if(start > 0 && !st[start - 1] && num[start] == num[start - 1])
            return;

        st[start] = 1;
        start++;
        dfs(num, start);
        start--;
        st[start] = 0;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);

        return res;
    }
};
// @lc code=end

