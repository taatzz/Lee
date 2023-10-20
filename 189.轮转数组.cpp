/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> tmp(n);

        for(int i = 0; i < n; i++)
        {
            tmp[(i + k) % n] = nums[i];
        }

        for(int i = 0; i < n; i++)
            nums[i] = tmp[i];
    }
};
// @lc code=end

