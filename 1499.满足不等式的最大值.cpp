/*
 * @lc app=leetcode.cn id=1499 lang=cpp
 *
 * [1499] 满足不等式的最大值
 */

// @lc code=start
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& nums, int k) {
        deque<pair<int, int>> q;

        int n = nums.size(), res = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            while(q.size() && nums[i][0] - q.front().first > k) q.pop_front();
        
            if(q.size())
                res = max(res, nums[i][0] + nums[i][1] + q.front().second);

            while(q.size() && nums[i][1] - nums[i][0] > q.back().second)  
                q.pop_back();
            q.push_back({nums[i][0], nums[i][1] - nums[i][0]});
        }

        return res;
    }
};
// @lc code=end

