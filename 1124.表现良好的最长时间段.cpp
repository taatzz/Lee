/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 *
 * [1124] 表现良好的最长时间段
 */

// @lc code=start
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // 连续子数组的长度转换为前缀和区间的差值
    /*
    劳累天数大于不劳累天数」等价于「劳累天数减去不劳累天数大于 0」。
    那么把劳累的一天视作 nums[i]=1，不劳累的一天视作 nums[i]=−1则问题变为：
    计算 num 的最长子数组，其元素和大于 0。
    既然说到了「子数组的元素和」，那么利用前缀和 s，将问题变为：
    找到两个下标 i 和 j，满足 j<i且 s[j]<s[i]，最大化 i−j 的值
    */
    int longestWPI(vector<int>& hours) {
        int res = 0, n = hours.size();
        vector<int> s(n + 1, 0);
        stack<int> stk;
       // stk.push(s[0] = 0);
        for(int i = 0; i <= n; i++)
        {
            if(i == 0)
                s[i] = 0;
            else
                s[i] = s[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
            if(stk.empty() || s[stk.top()] > s[i])
                stk.push(i);
        }

        for(int i = n; i >= 0; i--)
        {
            while(!stk.empty() && s[stk.top()] < s[i])
            {
                res = max(res, i - stk.top());
                stk.pop();
            }
        }

        return res;
    }
};
// @lc code=end

