/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 15;
    bool st[N];
    vector<int> tmp;
    vector<vector<int>> res;

    void dfs(vector<int>& num, int start)
    {
        tmp.clear();
        if(start >= num.size())
        {
            for(int i = 0; i < num.size(); i++)
            {
                // 保存选过的集合
                if(st[i])
                    tmp.push_back(num[i]);
            }
            // 结果保存路径
            res.push_back(tmp);
            return;
        }

        // 不选
        st[start] = 0;
        start++;
        dfs(num, start);
        start--;
        st[start] = 0;

        // 选
        st[start] = 1;
        start++;
        dfs(num, start);
        start--;
        st[start] = 0;
    }
    // 指数型枚举（每个位置都有选和不选两种情况）
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);

        return res;
    }
};
// @lc code=end

