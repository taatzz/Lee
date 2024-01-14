/*
 * @lc app=leetcode.cn id=2770 lang=cpp
 *
 * [2770] 达到末尾下标所需的最大跳跃次数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> f(n, -1);
        f[0] = 0;

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(abs(nums[i] - nums[j]) <= target && f[j] != -1)
                    f[i] = max(f[i], f[j] + 1);
            }
        }

        return f[n - 1];
    }
};
// @lc code=end

