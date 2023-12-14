/*
 * @lc app=leetcode.cn id=2132 lang=cpp
 *
 * [2132] 用邮票贴满网格图
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:

    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> a(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> s(m + 2, vector<int>(n + 2, 0));

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }

        for(int i = stampHeight; i <= m; i++)
        {
            for(int j = stampWidth; j <= n; j++)
            {
                int i1 = i - stampHeight + 1, j1 = j - stampWidth + 1;
                if(a[i][j] - a[i1 - 1][j] - a[i][j1 - 1] + a[i1 - 1][j1 - 1] == 0)
                {
                    s[i1][j1] += 1;
                    s[i + 1][j1] -= 1;
                    s[i1][j + 1] -= 1;
                    s[i + 1][j + 1] += 1;
                }
            }
        }

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++) s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(grid[i - 1][j - 1] == 0 && s[i][j] == 0)
                    return false;
            }
        }

        return true;
    }
};
// @lc code=end

