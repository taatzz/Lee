/*
 * @lc app=leetcode.cn id=2116 lang=cpp
 *
 * [2116] 判断一个括号字符串是否有效
 */

// @lc code=start
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n % 2) return 0;
        
        stack<int> left, a;
        for(int i = 0; i < n; i++)
        {
            if(locked[i] == '0') a.push(i);
            else if(s[i] == '(') left.push(i);
            else
            {
                if(s[i] == ')')
                {
                    if(left.size()) left.pop();
                    else if(a.size()) a.pop();
                    else return false;
                }
            }
        }

        if(left.size() > a.size()) return 0;
        while(left.size())
        {
            int l = left.top();
            int r = a.top();
            left.pop(), a.pop();
            if(l > r) return false;
        }

        return 1;
    }
};
// @lc code=end

