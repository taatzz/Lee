/*
 * @lc app=leetcode.cn id=2411 lang=cpp
 *
 * [2411] 按位或最大的最小子数组长度
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        for(int i = 0; i < n; i++)
        {
            res[i] = 1;
            for(int j = i - 1; j >= 0 && (nums[j] | nums[i]) != nums[j]; j--)
            {
                nums[j] |= nums[i];
                res[j] = i - j + 1;
            }
        }

        return res;
    }
};
// @lc code=end

