/*
 * @lc app=leetcode.cn id=866 lang=cpp
 *
 * [866] 回文素数
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 10010;
    typedef long long ll;

    int primePalindrome(int n) {
        vector<ll> t;
        auto init = [&]()
        {   
            for(int i = 1; i < N * 2; i++)
            {
                ll p = i;
                // 123 -> 12321
                for(ll x = p / 10; x; x /= 10)
                {
                    p = p * 10 + x % 10;
                }
                if(p < 2e8 + 10) t.push_back(p);
                p = i;
                // 123321
                for(ll x = p; x; x /= 10)
                {
                    p = p * 10 + x % 10;
                }
                if(p < 2e8 + 10) t.push_back(p);
            }
            sort(t.begin(), t.end());
        };
        init();

        int idx = lower_bound(t.begin(), t.end(), n) - t.begin();
        auto check = [&](ll x)->bool
        {
            if(x == 1) return false;
            for(int i = 2; i <= x / 2; i++)
                if(x % i == 0) return false;
            return true;
        };

        for(; idx < t.size(); idx++)
        {
            if(check(t[idx])) return t[idx];
        }

        return -1;
    }
};
// @lc code=end

