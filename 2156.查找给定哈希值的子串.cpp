/*
 * @lc app=leetcode.cn id=2156 lang=cpp
 *
 * [2156] 查找给定哈希值的子串
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    typedef long long LL;
    static const int N = 20010;
    LL hash[N], p[N];
    int m;

    LL find(int l, int r)
    {
        return ((hash[l] - hash[r + 1] * p[r - l + 1]) % m + m) % m;
    }

    string subStrHash(string s, int power, int mod, int k, int hashValue) {
        int n = s.size();
        m = mod;

        p[0] = 1;
        for(int i = 1; i <= n; i++) p[i] = p[i - 1] * power % mod;
        for(int i = n; i; i--) hash[i] = (hash[i + 1] * power + s[i - 1] - 'a' + 1) % mod;

        for(int i = 0; i <= n - k; i++)
        {
            if(find(i + 1, i + k) == hashValue) return s.substr(i, k);
        }

        return s;
    }
};
// @lc code=end

