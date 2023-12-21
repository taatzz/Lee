/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        // 初始化一个很大的数
        vector<vector<int>> f(m + 1, vector<int>(n + 2, 1e9));
        // 第一行是原始数据
        for(int i = 1; i <= n; i++) f[1][i] = matrix[0][i - 1];

        for(int i = 2; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                f[i][j] = min(min(f[i - 1][j - 1], f[i - 1][j]), f[i - 1][j + 1]) + matrix[i - 1][j - 1];
            }
        }

        int res = f[m][1]; // 答案为最后一行的最小值
        for(int i = 1; i <= n; i++) 
        {
            res = min(res, f[m][i]);
            // cout << f[m][i] << " ";
        }

        return res;
    }
};
// @lc code=end

