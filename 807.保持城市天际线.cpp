/*
 * @lc app=leetcode.cn id=807 lang=cpp
 *
 * [807] 保持城市天际线
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<int> row(m), col(n);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int x = min(row[i], col[j]);
                if(grid[i][j] < x) res += x - grid[i][j];
            }
        }

        return res;
    }
};
// @lc code=end

