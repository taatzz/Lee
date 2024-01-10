/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 *
 * [1329] 将矩阵按对角线排序
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 网格图的左对角线i-j相同，右对角线i+j相同
    vector<vector<int>> diagonalSort(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> h;
        int m = nums.size(), n = nums[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                h[i - j].push_back(nums[i][j]);
        }

        for(auto& e : h) 
        {
            sort(e.second.begin(), e.second.end());
        }

        for(int i = m - 1; i >= 0; i--)
            for(int j = n - 1; j >= 0; j--)
            {
                nums[i][j] = h[i - j].back();
                h[i - j].pop_back();
            }

        return nums;
    }
};
// @lc code=end

