/*
 * @lc app=leetcode.cn id=2162 lang=cpp
 *
 * [2162] 设置时间的最少代价
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int a, b, c;

    int f(int m, int s)
    {
        // 不合法输入
        if(m < 0 || m > 99 || s < 0 || s > 99) return INT_MAX;

        // 每个时间对应的数字
        vector<int> nums = { m / 10, m % 10, s / 10, s % 10 };
        // 前导0不算代价，从第一个合法位置开始计算
        int start = 0;
        while(start < 4 && nums[start] == 0) start++;

        int pre = c, res = 0;
        while(start < 4)
        {
            // 只要和前一个数字不一样需要加上movecost
            if(nums[start] != pre)
            {
                pre = nums[start];
                res += a;
            }
            res += b;
            start++;
        }

        return res;
    }

    int minCostSetTime(int startAt, int moveCost, int pushCost, int nums) {
        c = startAt, a = moveCost, b = pushCost;

        return min(f(nums / 60, nums % 60), f(nums / 60 - 1, nums % 60 + 60));
    }
};
// @lc code=end

