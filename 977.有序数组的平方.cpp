/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        int k = nums.size() - 1;
        vector<int> res(nums.size(), 0);
        for(i, j; i <= j; )
        {
            if(nums[i] * nums[i] < nums[j] * nums[j])
            {
                res[k--] = nums[j] * nums[j];
                j--;
            }
            else
            {
                res[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return res;
    }
};
// @lc code=end

