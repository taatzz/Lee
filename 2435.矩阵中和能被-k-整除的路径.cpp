/*
 * @lc app=leetcode.cn id=2435 lang=cpp
 *
 * [2435] 矩阵中和能被 K 整除的路径
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& nums, int k) {
        int n = nums.size(), m = nums[0].size(), mod = 1e9 + 7;

        long long f[n][m][k + 10];
        memset(f, 0, sizeof f);
        f[0][0][nums[0][0] % k] = 1;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                for(int t = 0; t < k; t++)
                {
                    if(i > 0) f[i][j][t] = (f[i][j][t] + f[i - 1][j][(t - nums[i][j] % k + k) % k]) % mod;
                    if(j > 0) f[i][j][t] = (f[i][j][t] + f[i][j - 1][(t - nums[i][j] % k + k) % k]) % mod;
                }
            }
        }

        return f[n - 1][m - 1][0];
    }
};
// @lc code=end

