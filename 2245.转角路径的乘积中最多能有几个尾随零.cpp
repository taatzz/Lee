/*
 * @lc app=leetcode.cn id=2245 lang=cpp
 *
 * [2245] 转角路径的乘积中最多能有几个尾随零
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> two(m, vector<int>(n)), five(m, vector<int>(n));
        vector<vector<int>> zero(m, vector<int>(n));

        auto find = [&](int x, int i, int j)
        {
            int t = x, cnt = 0;
            while(t % 2 == 0)
            {
                cnt++;
                t /= 2;
            }
            two[i][j] = cnt;
            t = x, cnt = 0;
            while(t % 5 == 0)
            {
                cnt++;
                t /= 5;
            }
            five[i][j] = cnt;
        };

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) find(grid[i][j], i, j);

        vector<vector<int>> two_row(m, vector<int>(n + 1)), five_row(m, vector<int>(n + 1));
        for(int i = 0; i < m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                two_row[i][j] = two_row[i][j - 1] + two[i][j - 1];
                five_row[i][j] = five_row[i][j - 1] + five[i][j - 1];
            }
        }
        int res = 0, a = 0, b = 0;
        for(int j = 0; j < n; j++)
        {
            a = 0, b = 0;
            for(int i = 0; i < m; i++)
            {
                res = max(res, min(two_row[i][j + 1] + a, five_row[i][j + 1] + b));
                res = max(res, min(two_row[i][n] - two_row[i][j] + a, five_row[i][n] - five_row[i][j] + b));
                a += two[i][j], b += five[i][j];
            }
            a = 0, b = 0;
            for(int i = m - 1; i >= 0; i--)
            {
                res = max(res, min(two_row[i][j + 1] + a, five_row[i][j + 1] + b));
                res = max(res, min(two_row[i][n] - two_row[i][j] + a, five_row[i][n] - five_row[i][j] + b));
                a += two[i][j], b += five[i][j];
            }
        }

        return res;
    }
};
// @lc code=end

