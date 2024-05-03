/*
 * @lc app=leetcode.cn id=1491 lang=cpp
 *
 * [1491] 去掉最低工资和最高工资后的工资平均值
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double average(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
    
        double res = 0.0;
        for(int i = 1; i < n - 1; i++) res += nums[i];

        return res / (n - 2);
    }
};
// @lc code=end

