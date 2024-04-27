/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int m = nums.size(), n = nums[0].size();

        for(int i = 0; i < m; i++)
        {
            int l = 0, r = nums[i].size() - 1;
            while(l < r)
            {
                int mid = (l + r) >> 1;
                if(nums[i][mid] >= target) r = mid;
                else l = mid + 1;
            }
            if(nums[i][l] == target) return true;
        }

        return false;
    }
};
// @lc code=end

