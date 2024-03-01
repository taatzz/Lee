/*
 * @lc app=leetcode.cn id=2327 lang=cpp
 *
 * [2327] 知道秘密的人数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> f(n + 1);
        int mod = 1e9 + 7;
        long long cur = 0, res = 0;
        f[0] = 1;
        for(int i = 0; i < n; i++)
        {
            if(i + delay >= n) cur = (cur + f[i]) % mod;
            for(int j = i + delay; j < min(i + forget, n); j++)
                f[j] = (f[j] + f[i]) % mod;
        }

        return (f[n - 1] + cur) % mod;
    }
};
// @lc code=end

