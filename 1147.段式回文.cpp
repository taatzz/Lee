/*
 * @lc app=leetcode.cn id=1147 lang=cpp
 *
 * [1147] 段式回文
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    static const int N = 1010, P = 131;
    typedef unsigned long long ULL;
    ULL h[N], p[N];

    ULL get(int l, int r)
    {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    int longestDecomposition(string text) {
        int n = text.size();

        p[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            h[i] = h[i - 1] * P + text[i - 1];
            p[i] = p[i - 1] * P;
        }

        int i = 0, j = n - 1;
        int k = 0;
        int res = 0;
        while(i <= j)
        {
            k = 0;
            bool flag = false;
            while(i + k < j - k)
            {
                int r = i + k, l = j - k;
                if(get(i + 1, r + 1) == get(l + 1, j + 1)) 
                {
                    i = r + 1, j = l - 1;
                    res += 2;
                    flag = true;
                    break;
                }
                k++;
            }
            if(!flag) 
            {
                res += 1;
                break;
            }
        }

        return res;
    }
};
// @lc code=end

