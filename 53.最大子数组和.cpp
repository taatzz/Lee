/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;    

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            cnt += nums[i];
            if(cnt > res)
                res = cnt;
            if(cnt <=0)
                cnt = 0;
        }
        return res;
    }
};
// @lc code=end

