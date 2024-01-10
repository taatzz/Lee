/*
 * @lc app=leetcode.cn id=1144 lang=cpp
 *
 * [1144] 递减元素使数组呈锯齿状
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    // 分别寻找满足条件的奇数型锯齿和偶数型锯齿因为可以无限的减小所以是一定存在的，然后比较两种操作的操作次数
    int find(vector<int> nums, int start)
    {
        int n = nums.size(), res = 0;

        for(int i = start; i < n; i += 2)
        {
            if(i - 1 >= 0)
            {
                if(nums[i - 1] >= nums[i])
                {
                    res += nums[i - 1] -  nums[i] + 1;
                    nums[i - 1] -= nums[i - 1] - nums[i] + 1;
                }
            }
            if(i + 1 < n)
            {
                if(nums[i + 1] >= nums[i])
                {
                    res += nums[i + 1] - nums[i] + 1;
                    nums[i + 1] -= nums[i + 1] - nums[i] + 1;
                }
            }
        }

        return res;
    }

    int movesToMakeZigzag(vector<int>& nums) {

        return min(find(nums, 0), find(nums, 1));
    }
};
// @lc code=end

