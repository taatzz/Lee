/*
 * @lc app=leetcode.cn id=2091 lang=cpp
 *
 * [2091] 从数组中移除最大值和最小值
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int mx = INT_MIN, mxidx = 0, mn = INT_MAX, mnidx = 0;
        for(int i = 0; i < n; i++)
        {
            if(mx < nums[i]) 
            {
                mx = nums[i];
                mxidx = i;
            }
            if(mn > nums[i])
            {
                mn = nums[i];
                mnidx = i;
            }
        }

        auto find = [&](int a, int b)->int
        {
            int l = a + 1, r = n - b;
            int sum1 = l + r, sum2 = b + 1, sum3 = n - a;

            return min({sum1, sum2, sum3});
        };

        return mxidx < mnidx ? find(mxidx, mnidx) : find(mnidx, mxidx);
    }
};
// @lc code=end

