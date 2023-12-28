/*
 * @lc app=leetcode.cn id=2302 lang=cpp
 *
 * [2302] 统计得分小于 K 的子数组数目
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();

        long long sum = 0;
        long long res = 0;
        for(int i = 0, j = 0; i < n; i++)
        {
            sum += nums[i];

            while((long long)sum * (i - j + 1) >= k)
            {
                sum -= nums[j++];
            }
            res += i - j + 1;
        }

        return res;
    }
};
// @lc code=end

