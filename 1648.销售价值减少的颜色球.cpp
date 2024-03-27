/*
 * @lc app=leetcode.cn id=1648 lang=cpp
 *
 * [1648] 销售价值减少的颜色球
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef long long LL;
    static const int mod = 1e9 + 7;

    bool check(vector<int>& nums, int x, int k)
    {
        int n = nums.size();
        LL res = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] >= x)
                res += nums[i] - x;
        }

        return res <= k;
    }

    int maxProfit(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // 二分找到最后所有球剩余的价值，那么多于部分等差数列求和
        // 最后如果没有满足需求再加上剩余需求 * 剩余价值
        int l = 0, r = nums[n - 1];
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(check(nums, mid, k)) r = mid;
            else l = mid + 1;
        }

        LL res = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > l)
            {
                res += ((LL)(nums[i] + l + 1) * (LL)(nums[i] - l)) / 2; 
                res %= mod;
                k -= nums[i] - l;
            }
        }
        res += (LL)l * k;
        res %= mod;

        return res;
    }
};
// @lc code=end

