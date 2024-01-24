/*
 * @lc app=leetcode.cn id=2320 lang=cpp
 *
 * [2320] 统计放置房子的方式数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int countHousePlacements(int n) {
        // 0当前位置不放,1当前位置放
        vector<vector<int>> f(n + 1, vector<int>(2));
        int mod = 1e9 + 7;

        f[0][0] = 1;
        f[1][0] = 1;
        f[1][1] = 1;

        // 当前位置不放方案数为f[i] = f[i - 1][0] + f[i - 1][1];
        // 当前位置放则i-1一定不能放，所以 f[i] = f[i - 2][0] + f[i - 2][1];
        for(int i = 2; i <= n; i++)
        {
            f[i][0] = (f[i - 1][1] + f[i - 1][0]) % mod;
            f[i][1] = (f[i - 2][1] + f[i - 2][0]) % mod;
        }

        int res = f[n][0] + f[n][1];

        return (long)res * res % mod;
    }
};
// @lc code=end

