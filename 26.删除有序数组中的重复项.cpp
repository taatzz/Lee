/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), write = 1, read = 1;

        for(; read < n; read++)
        {
            if(nums[read - 1] != nums[read])
            {
                nums[write++] = nums[read];
            }
        }

        return write;
    }
};
// @lc code=end

