/*
 * @lc app=leetcode.cn id=906 lang=cpp
 *
 * [906] 超级回文数
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef long long LL;
    vector<int> t;

    void init()
    {
        for(int i = 1; i <= 100000; i ++)
        {
            LL p = i;
            // 123 -> 12321
            for(LL x = p / 10; x; x /= 10)
            {
                p = (LL)p * 10 + x % 10;
            }
            if(p <= 1e9) t.push_back(p);

            // 123 -> 123321
            p = i;
            for(LL x = p; x; x /= 10)
            {
                p = (LL)p * 10 + x % 10;
            }
            if(p <= 1e9) t.push_back(p);
        }
        sort(t.begin(), t.end());
    }

    bool check(LL x)
    {
        x = x * x;
        string s = to_string(x);
        for(int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            if(s[i] != s[j]) return false;
        }

        return true;
    }

    int superpalindromesInRange(string left, string right) {
        init();
        LL lo = stoll(left), hi = stoll(right); 
        lo = sqrt(lo), hi = sqrt(hi);
        int l = lower_bound(t.begin(), t.end(), lo) - t.begin();
        int r = upper_bound(t.begin(), t.end(), hi) - t.begin();
        
        int res = 0;
        for(int i = l; i < r; i++)
        {
            if(check(t[i])) res++;
        }

        return res;
    }
};
// @lc code=end

