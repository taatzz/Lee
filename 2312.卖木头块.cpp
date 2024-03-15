/*
 * @lc app=leetcode.cn id=2312 lang=cpp
 *
 * [2312] 卖木头块
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    long long sellingWood(int n, int m, vector<vector<int>>& prices) {
        vector<vector<int>> w(n + 1, vector<int>(m + 1, 0));
        for(auto& e : prices)
        {
            int a = e[0], b = e[1], c = e[2];
            w[a][b] = c;
        }

        vector<vector<long long>> f(n + 1, vector<long long>(m + 1));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                f[i][j] = w[i][j];
                for(int k = 1; k < i; k++) f[i][j] = max(f[i][j], f[k][j] + f[i - k][j]);
                for(int k = 1; k < j; k++) f[i][j] = max(f[i][j], f[i][k] + f[i][j - k]);
            }
        }

        return f[n][m];
    }
};
// @lc code=end

