/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    // 数组分为 有序，无序，有序
    // 每次比较当前元素与前面元素的最大值，如果存在逆序更新左边界和右边界
    // 然后将前面序列的最大值继续插入到栈中
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> stk;
        int start = INT_MAX, end = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(stk.empty() || nums[stk.top()] <= nums[i])
                stk.push(i);
            else
            {
                int maxval = stk.top();
                end = max(end, i);
                while(!stk.empty() && nums[stk.top()] > nums[i])
                {
                    start = min(stk.top(), start);
                    stk.pop();
                }
                stk.push(maxval);
            }
        }

        return start < end ? end - start + 1 : 0;
    }
};
// @lc code=end

