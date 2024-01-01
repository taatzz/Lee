/*
 * @lc app=leetcode.cn id=1599 lang=cpp
 *
 * [1599] 经营摩天轮的最大利润
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& nums, int pro, int cost) {
        int n = nums.size();

        int pre = 0, sum = 0, num = 0, i = 0;
        pair<int, int> res = { INT_MIN, 0 };
        for(; i < n || pre; i++)
        {
            if(i < n && nums[i] + pre <= 4)
            {
                sum = (nums[i] + pre + num) * pro - (i + 1) * cost;
                num += nums[i] + pre;
                pre = 0;
            }
            else if(i < n && nums[i] + pre > 4)
            {
               sum = (num + 4) * pro - (i + 1) * cost;
               pre = nums[i] + pre - 4;
               num += 4;
            }
            else
            {
                if(pre >= 4) 
                {
                    sum = (num + 4) * pro - (i + 1) * cost;
                    pre -= 4;
                    num += 4;
                }
                else if(pre > 0)
                {
                     sum = (num + pre) * pro - (i + 1) * cost;
                     num += pre;
                     pre = 0;
                }
            }
            if(sum > res.first)
            {
                res.first = sum;
                res.second = i + 1;
            }
        }

        return res.first <= 0 ? -1 : res.second;
    }
};
// @lc code=end

