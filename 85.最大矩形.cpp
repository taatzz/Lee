/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> l(n, -1), r(n, n);

        stack<int> stk;
        for(int i = 0; i < n; i++)
        {
            while(stk.size() && nums[stk.top()] > nums[i])
            {
                r[stk.top()] = i;
                stk.pop();
            }
            if(stk.size()) l[i] = stk.top();
            stk.push(i);
        }

        for(int i = 0; i < n; i++)
            res = max(res, (r[i] - l[i] - 1) * nums[i]);

        return res;
    }

    int maximalRectangle(vector<vector<char>>& nums) {
        int res = 0, m = nums.size(), n = nums[0].size();

        vector<int> s(n + 1);

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(nums[i][j] == '1') s[j + 1] += 1;
                else s[j + 1] = 0;
            }

            res = max(res, largestRectangleArea(s));
        }

        return res;
    }
};
// @lc code=end

