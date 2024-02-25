/*
 * @lc app=leetcode.cn id=1392 lang=cpp
 *
 * [1392] 最长快乐前缀
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    typedef unsigned long long ULL;
    static const int N = 100010, P = 131;
    ULL pre[N], p[N];

    ULL get(int l, int r)
    {
        return pre[r] - pre[l - 1] * p[r - l + 1];
    }

    string longestPrefix(string s) {
        int n = s.size();

        p[0] = 1;
        for(int i = 1; i <= n; i++) 
        {
            pre[i] = pre[i - 1] * P + s[i - 1];
            p[i] = p[i - 1] * P;
        }   

        int res = -1;
        for(int i = 0, j = n; i < n - 1; i++)
        {
            if(get(1, i + 1) == get(j - i, j)) res = max(res, i);
        }

        return res == -1 ? "" : s.substr(0, res + 1);
    }
};
// @lc code=end

