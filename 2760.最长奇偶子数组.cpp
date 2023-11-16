/*
 * @lc app=leetcode.cn id=2760 lang=cpp
 *
 * [2760] 最长奇偶子数组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2 == 0 && nums[i] <= threshold)
            {
                int j = i + 1;
                while(j < n && nums[j] <= threshold && nums[j] % 2 != nums[j - 1] % 2)
                    j ++;
                res = max(res, j - i);
            }
        }

        return res;
    }
};
// @lc code=end

