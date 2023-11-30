/*
 * @lc app=leetcode.cn id=2401 lang=cpp
 *
 * [2401] 最长优雅子数组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    // 双指针，类似求最长无重复元素的子数组写法
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int res = 0, tmp = 0;
        for(int i = 0, j = 0; j < n; j++)
        {
            while(tmp & nums[j]) tmp ^= nums[i++];// 子数组重复将左端点缩小

            tmp += nums[j]; // 无重复将右端点加入
            res = max(res, j - i + 1); // 计算答案
        }

        return res;
    }
};
// @lc code=end

