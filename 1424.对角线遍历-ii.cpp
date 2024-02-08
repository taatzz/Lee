/*
 * @lc app=leetcode.cn id=1424 lang=cpp
 *
 * [1424] 对角线遍历 II
 */

// @lc code=start
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> h;

        int m = nums.size(), n = nums[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < nums[i].size(); j++)
                h[i + j].push_back(nums[i][j]);
        }

        vector<int> res;
        for(auto& [_, e] : h)
        {
            for(int i = e.size() - 1; i >= 0; i--) res.push_back(e[i]);
        }

        return res;
    }
};
// @lc code=end

