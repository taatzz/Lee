/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        bool flag = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            flag = true;
            if(i - 1 >= 0)
            {
                if(nums[i] < nums[i - 1]) flag = false;
            }
            if(i + 1 < n)
            {
                if(nums[i] < nums[i + 1]) flag = false;
            }
            if(flag) return i;
        }
        
        return 0;
    }
};
// @lc code=end

