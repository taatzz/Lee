/*
 * @lc app=leetcode.cn id=2017 lang=cpp
 *
 * [2017] 网格游戏
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:

    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size(), m = 2;
        vector<vector<long long>> s(m, vector<long long>(n + 10));

        for(int i = 0; i < m; i++)
        {
            for(int j = 1; j <= n; j++)
                s[i][j] = s[i][j - 1] + grid[i][j - 1];
        }

        long long res = 3e9;
        for(int i = 0; i < n; i++)
        {
            long long l = s[0][i + 1], r = s[1][n] - s[1][i];

            res = min(res, max(s[0][n] - l, s[1][n] - r));
        }

        return res;
    }
};
// @lc code=end

