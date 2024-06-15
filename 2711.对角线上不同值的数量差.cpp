/*
 * @lc app=leetcode.cn id=2711 lang=cpp
 *
 * [2711] 对角线上不同值的数量差
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));

        auto find = [&](int x, int y)->int
        {
            unordered_set<int> h1, h2;
            for(int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
                h1.insert(grid[i][j]);
            for(int i = x + 1, j = y + 1; i < m && j < n; i++, j++)
                h2.insert(grid[i][j]);
            
            int i = h1.size(), j = h2.size();

            return abs(i - j);
        };

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                res[i][j] = find(i, j);
            }
        }

        return res;
    }
};
// @lc code=end

