/*
 * @lc app=leetcode.cn id=2740 lang=cpp
 *
 * [2740] 找出分区值
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            if(i + 1 < n) res = min(res, nums[i + 1] - nums[i]);
        }
        
        return res;
    }
};
// @lc code=end

