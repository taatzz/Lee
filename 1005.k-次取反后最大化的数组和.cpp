/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                k--;
                nums[i] = -nums[i];
            }
            else 
            {
                while(k)
                {
                    nums[i] = -nums[i];
                    k--;
                }
            }
            res += nums[i];
        }

        return res;
    }
};
// @lc code=end

