/*
 * @lc app=leetcode.cn id=1220 lang=cpp
 *
 * [1220] 统计元音字母序列的数目
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1e9 + 7;
        vector<vector<long long>> f(n, vector<long long>(5));

        f[0][0] = 1;
        f[0][1] = 1;
        f[0][2] = 1;
        f[0][3] = 1;
        f[0][4] = 1;

        for(int i = 1; i < n; i++)
        {
            f[i][0] += f[i - 1][1];
            f[i][1] += f[i - 1][0] + f[i - 1][2];
            f[i][2] += f[i - 1][0] + f[i - 1][1] + f[i - 1][3] + f[i - 1][4];
            f[i][3] += f[i - 1][2] + f[i - 1][4];
            f[i][4] += f[i - 1][0];

            for(int j = 0; j < 5; j++) f[i][j] %= mod;
        }

        long long res = f[n - 1][0] + f[n - 1][1] + f[n - 1][2] + f[n - 1][3] + f[n - 1][4];

        return res % mod;
    }
};
// @lc code=end

