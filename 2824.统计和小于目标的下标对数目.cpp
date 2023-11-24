/*
 * @lc app=leetcode.cn id=2824 lang=cpp
 *
 * [2824] 统计和小于目标的下标对数目
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int res = 0;
        for(int l = 0, r = n - 1; l < n; l++)
        {
            while(l < r && nums[l] + nums[r] >= target) r--;
            if(l < r) res += r - l;
        }

        return res;
    }
};
// @lc code=end

