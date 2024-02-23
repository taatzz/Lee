/*
 * @lc app=leetcode.cn id=1605 lang=cpp
 *
 * [1605] 给定行和列的和求可行矩阵
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        int m = row.size(), n = col.size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
        {
            int x = row[i];
            for(int j = 0; j < n && x; j++)
            {
                if(col[j] >= x)
                {
                    res[i][j] = x;
                    col[j] -= x;
                    x = 0;
                }
                else 
                {
                    res[i][j] = col[j];
                    x -= col[j];
                    col[j] = 0;
                }
            }
        }

        return res;
    }
};
// @lc code=end

