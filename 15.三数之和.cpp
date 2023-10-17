// @before-stub-for-debug-begin
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> threeSum(vector<int>& nums) {
        int left, right;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[0] > 0)
                return res;
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            left = i + 1, right = nums.size() - 1;
            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else if(nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else
                {
                    res.push_back(vector<int>{ nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }   
            }
        }

        return res;
    }
};
// @lc code=end

