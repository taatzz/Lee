/*
 * @lc app=leetcode.cn id=2732 lang=cpp
 *
 * [2732] 找到矩阵中的好子集
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        unordered_map<int, int> h;

        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            int t = 0;
            for(int j = 0; j < n; j++)
                if(grid[i][j]) t |= 1 << j;
            h[t] = i;
            if(t == 0) return {i};
        }

        for(auto [k, e] : h)
        {
            for(auto [x, i] : h)
                if((k & x) == 0)
                    return {min(i, e), max(i, e)};
        }

        return {};
    }
};
// @lc code=end

