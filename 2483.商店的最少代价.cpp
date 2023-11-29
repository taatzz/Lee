/*
 * @lc app=leetcode.cn id=2483 lang=cpp
 *
 * [2483] 商店的最少代价
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int a[N], s[N];

    int bestClosingTime(string customers) {
        int n = customers.size();
        int t = 1;
        for(int i = 0; i < customers.size(); i++)
        {
            if(customers[i] == 'Y') a[t++] = 1;
            else a[t++] = 0;
        }

        for(int i = 1; i <= n; i++)
        {
            s[i] = s[i - 1] + a[i];
        }

        int res = INT_MAX, ans = 0;
        for(int i = 1; i <= n + 1/*可以在n的时候关门*/; i ++)
        {
            // 在i关门的时候就是已经关门了开始算关门之后的前缀和
            int left = s[i - 1], right = s[n] - s[i - 1];
            int tmp = i - 1 - left + right;
            if(tmp < res)
            {
                res = tmp;
                ans = i - 1;
            }
        }

        return ans;
    }
};
// @lc code=end

