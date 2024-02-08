/*
 * @lc app=leetcode.cn id=1895 lang=cpp
 *
 * [1895] 最大的幻方
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 55;
    int row[N][N], col[N][N];

    bool check(vector<vector<int>>& nums, int x1, int y1, int x2, int y2)
    {
        int pre = row[x1 + 1][y2 + 1] - row[x1 + 1][y1];
        // 行
        for(int i = x1 + 1; i <= x2; i++)
        {
            int x = row[i + 1][y2 + 1] - row[i + 1][y1];
            if(pre != x) return false;
        }
        // 列
        for(int i = y1; i <= y2; i++)
        {
            int x = col[x2 + 1][i + 1] - col[x1][i + 1];
            if(x != pre) return false;
        }
        // 对角线
        int a = x1 + y2, b = x1 - y1;
        int sum1 = 0, sum2 = 0;
        for(int i = x1; i <= x2; i++)
        {
            for(int j = y1; j <= y2; j++)
            {
                if(i + j == a) sum1 += nums[i][j];
                if(i - j == b) sum2 += nums[i][j];
            }
        }

        return sum1 == pre && sum2 == pre;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                row[i][j] = row[i][j - 1] + grid[i - 1][j - 1];
            }
        }

        for(int j = 1; j <= n; j++)
            for(int i = 1; i <= m; i++)
                col[i][j] = col[i - 1][j] + grid[i - 1][j - 1];

        int k = min(m, n);

        for(; k > 1; k--)
        {
            for(int i = 0; i < m - k + 1; i++)
            {
                for(int j = 0; j < n - k + 1; j++)
                {
                    int x = i + k - 1, y = j + k - 1;
                    if(check(grid, i, j, x, y))
                    {
                        return k;
                    }
                }
            }
        }

        return 1;
    }
};
// @lc code=end

