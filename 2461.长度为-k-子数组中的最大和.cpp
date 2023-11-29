/*
 * @lc app=leetcode.cn id=2461 lang=cpp
 *
 * [2461] 长度为 K 子数组中的最大和
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    long long s[N];
    int cnt[N];

    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
            s[i + 1] = s[i] + nums[i];

        long long res = 0;
        for(int l = 0, r = 0; r < n; r ++)
        {
            cnt[nums[r]]++;
            while(l < r && cnt[nums[r]] > 1) 
            {
                cnt[nums[l++]]--;
            }
            if(r - l >= k - 1)
            {
                long long tmp = nums[r + 1] - nums[l];
                res = max(res, tmp);
                cnt[nums[l++]]--;
            }
        }

        return res;
    }
};
// @lc code=end

