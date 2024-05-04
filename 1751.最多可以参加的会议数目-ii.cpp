/*
 * @lc app=leetcode.cn id=1751 lang=cpp
 *
 * [1751] 最多可以参加的会议数目 II
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        vector<vector<int>> nums;
        for(auto& e : events) 
        {
            nums.push_back({e[1], e[0], e[2]});
        }
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> f(n + 1, vector<int>(k + 1));
        for(int i = 0; i < n; i++)
        {
            int p = upper_bound(nums.begin(), nums.begin() + i, vector<int>{nums[i][1] - 1, INT_MAX}) - nums.begin();
            for(int j = 1; j <= k; j++)
                f[i + 1][j] = max(f[i][j], f[p][j - 1] + nums[i][2]);
        }

        return f[n][k];
    }
};
// @lc code=end

