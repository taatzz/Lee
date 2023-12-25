/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double res = INT_MIN, sum = 0;

        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            if(i >= k - 1)
            {
                int j = i - k + 1;
                res = max(res, sum / k);
                sum -= nums[j];
            }
        }

        return res;
    }
};
// @lc code=end

