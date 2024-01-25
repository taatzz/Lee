/*
 * @lc app=leetcode.cn id=1249 lang=cpp
 *
 * [1249] 移除无效的括号
 */

// @lc code=start
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    bool st[N];

    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> stk;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(') stk.push(i);
            else if(s[i] == ')')
            {
                if(!stk.empty() && s[stk.top()] == '(') stk.pop();
                else stk.push(i);
            }
        }

        while(stk.size())
        {
            st[stk.top()] = 1;
            stk.pop();
        }


        string res;
        for(int i = 0; i < n; i++)
            if(!st[i]) res.push_back(s[i]);

        return res;
    }
};
// @lc code=end

