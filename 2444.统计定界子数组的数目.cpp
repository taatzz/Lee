/*
 * @lc app=leetcode.cn id=2444 lang=cpp
 *
 * [2444] 统计定界子数组的数目
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;

        int n = nums.size();
        int maxi = -1, mini = -1, p0 = -1;
        for(int i = 0; i < n; i++)
        {   
            if(nums[i] == minK) mini = i;
            if(nums[i] == maxK) maxi = i;
            if(nums[i] < minK || nums[i] > maxK) p0 = i;

            res += max(min(mini, maxi) - p0, 0);
        }

        return res;
    }
};
// @lc code=end

