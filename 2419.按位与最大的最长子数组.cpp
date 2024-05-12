/*
 * @lc app=leetcode.cn id=2419 lang=cpp
 *
 * [2419] 按位与最大的最长子数组
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int res = 1, i = 0, n = nums.size();
        while(i < n)
        {
            if(nums[i] == mx)
            {
                int start = i;
                i++;
                while(i < n && nums[i] == nums[i - 1]) i++;
                res = max(res, i - start);
            }
            else i++;
        }

        return res;
    }
};
// @lc code=end

