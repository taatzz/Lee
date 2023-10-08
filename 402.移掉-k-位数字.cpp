/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉 K 位数字
 */

// @lc code=start
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k)
            return "0";

        stack<char> stk;

        for(auto ch : num)
        {
            if(!stk.empty() && k > 0)
            {
                while(!stk.empty() && stk.top() > ch && k) // 栈顶元素大于当前元素删除
                {
                    k--;
                    stk.pop();
                }
            }
            stk.push(ch);
        }
        while(k--) // 数字单调递增删除数字的最后一位
            stk.pop();

        stack<char> st;
        while(!stk.empty())
        {
            st.push(stk.top());
            stk.pop();
        }

        string res;
        bool flag = true; // 标志位判断是否含有前导0
        while(!st.empty())
        {
            if(flag && st.top() == '0') // 删除前导0
            {
                st.pop();
                continue;
            }
            res += st.top();
            flag = false;
            st.pop();
        }

        return res == "" ? "0" : res; // 判断删除之后是否是空序列
    }
};
// @lc code=end

