/*
 * @lc app=leetcode.cn id=2482 lang=cpp
 *
 * [2482] 行和列中一和零的差值
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> row(m, vector<int>(n + 1));
        vector<vector<int>> col(m + 1, vector<int>(n));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                row[i][j + 1] = row[i][j] + grid[i][j];
        for(int j = 0; j < n; j++)
            for(int i = 0; i < m; i++)
                col[i + 1][j] = col[i][j] + grid[i][j];
        vector<vector<int>> res(m, vector<int>(n));
        for(int i = 0; i < m; i++)
        {
            int a = row[i][n];
            for(int j = 0; j < n; j++)
            {
                int b = col[m][j];
                res[i][j] = a + b - (n - a) - (m - b);
            }
        }

        return res;
    }
};
// @lc code=end

