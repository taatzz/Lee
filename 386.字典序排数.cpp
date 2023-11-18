/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> res;

    void dfs(int p, int x)
    {
        if(p > x)
            return;
        res.push_back(p);
        for(int i = 0; i < 10; i++)
        {
            dfs(p * 10 + i, x);
        }
    }

    vector<int> lexicalOrder(int n) {
        for(int i = 1; i <= 9; i++)
            dfs(i, n);

        return res;
    }
};
// @lc code=end

