/*
 * @lc app=leetcode.cn id=2679 lang=cpp
 *
 * [2679] 矩阵中的和
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();
        int res = 0;

        for(int i = 0; i < m; i++) sort(nums[i].begin(), nums[i].end());
        for(int i = 0; i < n; i++)
        {
            int mx = 0;
            for(int j = 0; j < m; j++)
                mx = max(mx, nums[j][i]);
            res += mx;
        }

        return res;
    }
};
// @lc code=end

