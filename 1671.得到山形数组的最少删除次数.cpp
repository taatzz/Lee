/*
 * @lc app=leetcode.cn id=1671 lang=cpp
 *
 * [1671] 得到山形数组的最少删除次数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1);

        // 最长递增子数组，left[i] 表示以i为结尾的前i个数字中的最长上升子序列
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                    left[i] = max(left[i], left[j] + 1);
            }
        }
        vector<int> right(n, 1);
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = n - 1; j > i; j--)
            {
                if(nums[i] > nums[j])
                    right[i] = max(right[i], right[j] + 1);
            }
        }

        int res = 0;
        // 山形数组需要开头和结尾不删除，所以我们求每个位置的最长上升子序列然后相减
        for(int i = 0; i < n; i++)
        {
            if(left[i] > 1 && right[i] > 1) // 山形数组的长度大于3
                res = max(res, left[i] + right[i] - 1);
        }

        return n - res;
    }
};
// @lc code=end

