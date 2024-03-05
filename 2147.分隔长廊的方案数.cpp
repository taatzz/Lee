/*
 * @lc app=leetcode.cn id=2147 lang=cpp
 *
 * [2147] 分隔长廊的方案数
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    int numberOfWays(string s) {
        int n = s.size(), mod = 1e9 + 7;

        int pre = -1, cnt = 0, res = 1;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'S') 
            {
                cnt++;
                if(cnt >= 3 && cnt %  2 == 1) res = (long long) res * (i - pre) % mod;
                pre = i;
            }
        }

        if(cnt < 2 || cnt & 1) res = 0;

        return res;
    }
};
// @lc code=end

