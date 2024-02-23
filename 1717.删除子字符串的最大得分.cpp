/*
 * @lc app=leetcode.cn id=1717 lang=cpp
 *
 * [1717] 删除子字符串的最大得分
 */

// @lc code=start
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    bool st[N];

    int f(string s, string t)
    {
        stack<int> stk;
        int cnt = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(st[i]) continue;
            if(s[i] == t[1])
            {
                if(stk.size() && s[stk.top()] == t[0])
                {
                    cnt++;
                    st[i] = true;
                    st[stk.top()] = true;
                    stk.pop();
                }
                else stk.push(i);
            }
            else stk.push(i);
        }
        
        return cnt;
    }

    int maximumGain(string s, int x, int y) {
        if(x > y)
        {
            return f(s, "ab") * x + f(s, "ba") * y;
        }
        else
        {
            return f(s, "ba") * y + f(s, "ab") * x;
        }
    }
};
// @lc code=end

