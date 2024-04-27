/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int m = nums.size(), n = nums[0].size();

        int l = 0, r = m * n - 1;
        while(l  < r)
        {
            int mid = (l + r) >> 1;
            if(nums[mid / n][mid % n] >= target) r = mid;
            else l = mid + 1;
        }

        return nums[l / n][l % n] == target;
    }
};
// @lc code=end

