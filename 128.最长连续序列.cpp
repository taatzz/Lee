/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int res = 1, len = 1; // 保存结果

        for(int i = 1; i < nums.size() - 1; i++)
        {
            if(nums[i + 1] - nums[i] == 1)
            {
                len++;
            }
            else if(nums[i+1] == nums[i])
                continue;
            else
                len = 1;
            res = max(res, len);
        }

        return res;
    }
};
// @lc code=end

