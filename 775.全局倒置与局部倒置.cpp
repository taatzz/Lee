/*
 * @lc app=leetcode.cn id=775 lang=cpp
 *
 * [775] 全局倒置与局部倒置
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size(), min_num = nums[n - 1];

        for(int i = n - 3; i >= 0; i--)
        {
            if(nums[i] > min_num) return false;
            min_num = min(min_num, nums[i + 1]);
        }

        return true;
    }
};
// @lc code=end

