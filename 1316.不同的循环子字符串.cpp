/*
 * @lc app=leetcode.cn id=1316 lang=cpp
 *
 * [1316] 不同的循环子字符串
 */

// @lc code=start
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    typedef unsigned long long ULL;
    static const int N = 2010, P = 131;
    ULL h[N], p[N];

    ULL get(int l, int r)
    {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    int distinctEchoSubstrings(string s) {
        int n = s.size();
        unordered_set<ULL> hash;

        p[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            h[i] = h[i - 1] * P + s[i - 1];
            p[i] = p[i - 1] * P;
        }

        int res = 0;
        // 枚举起始位置和长度
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                int len = j - i + 1, r = j + len;
                // 后半段长度不符合要求就直接退出
                if(r >= n) break;
                // 不能重复
                if(get(i + 1, j + 1) == get(j + 2, r + 1) && !hash.count(get(i + 1, j + 1))) 
                {
                    hash.insert(get(i + 1, j + 1));
                    res++;
                }
            }
        }

        return res;
    }
};
// @lc code=end

