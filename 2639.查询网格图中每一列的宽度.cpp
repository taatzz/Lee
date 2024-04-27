/*
 * @lc app=leetcode.cn id=2639 lang=cpp
 *
 * [2639] 查询网格图中每一列的宽度
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> res;
        for(int j = 0; j < n; j++)
        {
            int mx = 0;
            for(int i = 0; i < m; i++)
            {
                string s = to_string(grid[i][j]);
                mx = max(mx, (int)s.size());
            }
            res.push_back(mx);
        }

        return res;
    }
};
// @lc code=end

