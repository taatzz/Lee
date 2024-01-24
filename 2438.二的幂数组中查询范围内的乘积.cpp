/*
 * @lc app=leetcode.cn id=2438 lang=cpp
 *
 * [2438] 二的幂数组中查询范围内的乘积
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    long long s[50];
    int idx = 1;
    int mod = 1e9 + 7;

    int qmi(long long a, int b)
    {
        int res = 1;
        while(b)
        {
            if(b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }

        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        s[0] = 1;


        for(int i = 0; i < 32; i++)
        {
            if((n & (1 << i)) == (1 << i))
            {
                s[idx] = (long long)s[idx - 1] * (1 << i) % mod;
                idx++;
            }
        }

        int a[50];
        a[0] = 1;
        for(int i = 1; i < idx; i++)
        {
            a[i] = qmi(s[i], mod - 2);
        }

        vector<int> res;
        for(auto e : queries)
        {
            int l = e[0], r = e[1];
            res.push_back(1ll * s[r + 1] * a[l] % mod);
        }

        return res;
    }
};
// @lc code=end

