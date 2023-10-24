/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), write = 0, read = 0;

        while(read < n)
        {
            if(nums[read] != val)
                nums[write++] = nums[read++];
            else
                read++;
        }

        return write;
    }
};
// @lc code=end

