/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <string>
#include <stack>

using namespace std;

class Solution {
public:

    bool check(const string& s, int a, int b)
    {
        if(s[a] == '(' && s[b] == ')')
            return true;
        else if(s[a] == '[' && s[b] == ']')
            return true;
        else if(s[a] == '{' && s[b] == '}')
            return true;
        else
            return false;
    }

    bool isValid(string s) {
        stack<int> sc;
        if(s.size() % 2)
            return  false;
        for(int i = 0; i < s.size(); i++)
        {
            if(!sc.empty() && check(s, sc.top(), i))
            {
                sc.pop();
                continue;
            }
            sc.push(i);
        }
        return sc.empty();
    }
};
// @lc code=end

