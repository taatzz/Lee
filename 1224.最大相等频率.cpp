/*
 * @lc app=leetcode.cn id=1224 lang=cpp
 *
 * [1224] 最大相等频率
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int cnt[N], sum[N];

    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size();

        int res = 0, mx = 0;
        for(int i = 0; i < n; i++)
        {
            int x = nums[i], cur = ++cnt[x], len = i + 1;
            sum[cur]++, sum[cur - 1] --;
            mx = max(mx, cur);

            if(mx == 1) res = len;
            if(mx * sum[mx] + 1 == len) res = len;
            if((mx - 1) * (sum[mx - 1] + 1) + 1 == len) res = len;
        }

        return res;
    }   
};
// @lc code=end

