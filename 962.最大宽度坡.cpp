/*
 * @lc app=leetcode.cn id=962 lang=cpp
 *
 * [962] 最大宽度坡
 */

// @lc code=start
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;

        // 先创建一个严格单调递减栈，然后从尾部开始遍历宽度
        for(int i = 0; i < nums.size(); i++)
        {
            if(s.empty() || nums[s.top()] > nums[i])
                s.push(i);
        }

        int res = 0;
        for(int i = nums.size() - 1; i >= res; i--)
        {
            while(!s.empty() && nums[i] >= nums[s.top()])
            {
                res = max(res, i - s.top());
                s.pop();
            }
        }

        return res;
    }
};
// @lc code=end

