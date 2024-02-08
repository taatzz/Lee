/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

// @lc code=start
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();

        map<int, vector<int>> h;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                h[i + j].push_back(nums[i][j]);
            }
        }

        vector<int> res;
        int k = 0;
        for(auto& [_, e] : h)
        {
            if(k % 2 == 0)
            {
                for(int i = e.size() - 1; i >= 0; i--) res.push_back(e[i]);
            }
            else
                for(int i = 0; i < e.size(); i++) res.push_back(e[i]);
            k++;
        }

        return res;
    }
};
// @lc code=end

