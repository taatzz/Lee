/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& newInterval) {
        nums.push_back({newInterval[0], newInterval[1]});
        sort(nums.begin(), nums.end());

        int st = 1e9, ed = -1e9;
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++)
        {
            int l = nums[i][0], r = nums[i][1];
            if(l > ed)
            {
                if(ed != -1e9) res.push_back({st, ed});
                st = l, ed = r;
            }
            else ed = max(ed, r);
        }
        res.push_back({st, ed});

        return res;
    }
};
// @lc code=end

