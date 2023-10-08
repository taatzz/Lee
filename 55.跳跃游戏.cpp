/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        int length = 0;
        for(int i = 0; i <= length; i++)
        {
            length = max(i + nums[i], length);
            if(length >= nums.size() - 1)
                return true;
        }

        return false;
    }
};
// @lc code=end

