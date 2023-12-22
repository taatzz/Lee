/*
 * @lc app=leetcode.cn id=2256 lang=cpp
 *
 * [2256] 最小平均差
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    long long s[N];

    // 前缀和空间也可以优化
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();

        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];

        vector<long long> left(n), right(n);
        for(int i = 0; i < n; i++) left[i] = (long long)s[i + 1] / (i + 1);
        for(int i = n - 2; i >= 0; i--) right[i] = (long long)(s[n] - s[i + 1]) / (n - i - 1);

        int res = INT_MAX;
        int ans = 0;
        for(int i = 0; i < n; i++) 
        {
            int t = abs(left[i] - right[i]);
            if(t < res)
            {
                ans = i;
                res = t;
            }
        }

        return ans;
    }
};
// @lc code=end

