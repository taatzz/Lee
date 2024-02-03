/*
 * @lc app=leetcode.cn id=1359 lang=cpp
 *
 * [1359] 有效的快递序列数目
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int mod = 1e9 + 7;

    int countOrders(int n) {
        if(n == 1) return 1;

        vector<int> f(n + 1);
        // 第i个快递如果整体考虑前i + 1 个快递共有(i - 1) * 2 + 1 => 2i - 1
        // 分开考虑就是2(i - 1) + 1 个位置选择两个，
        f[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            f[i] = (long long)(2 * i - 1) * i * f[i - 1] % mod;
        }

        return f[n];
    }
};
// @lc code=end

