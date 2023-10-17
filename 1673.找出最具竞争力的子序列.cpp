/*
 * @lc app=leetcode.cn id=1673 lang=cpp
 *
 * [1673] 找出最具竞争力的子序列
 */

// @lc code=start
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 维护单调递增栈，然后去寻找更小的元素，数组剩余长度小于k的差值时不能删除
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> stk;
        vector<int> res;

        for(int i = 0; i < n; i++)
        {
            int right = n - i; // 记录右边剩余元素，右边剩余元素小于当前所求的k的差值时不可以删除
            while(!stk.empty() && nums[i] < nums[stk.top()] && stk.size() + right > k)
            {
                stk.pop();
            }
            // 没有满足k就插入
            if(stk.size() < k)
                stk.push(i);
        }
        while(k--)
        {
            res.push_back(nums[stk.top()]);
            stk.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end

