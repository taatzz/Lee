/*
 * @lc app=leetcode.cn id=2369 lang=cpp
 *
 * [2369] 检查数组是否存在有效划分
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);
        f[0] = 1;

        for(int i = 1; i < n; i++)
        {
            if(i - 1 >= 0 && nums[i] == nums[i - 1] && f[i - 1])
                f[i + 1] = true;
            else if(i - 2 >= 0 && f[i - 2] && (nums[i - 2] == nums[i] && nums[i] == nums[i - 1] ||
            (nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2)))
            {
                f[i + 1] = true;
            }
        }

        return f[n];
    }
};
// @lc code=end

