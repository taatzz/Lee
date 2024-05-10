/*
 * @lc app=leetcode.cn id=2033 lang=cpp
 *
 * [2033] 获取单值网格的最小操作数
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& g, int x) {
        int m = g.size(), n = g[0].size();
        vector<int> t;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                t.push_back(g[i][j]);
        }

        sort(t.begin(), t.end());
        int k = t[t.size() / 2];
        int res = 0;

        for(int i = 0; i < t.size(); i++)
        {
            if(abs(t[i] - k) % x != 0) return -1;
            res += abs(t[i] - k) / x;
        }

        return res;
    }
};
// @lc code=end

