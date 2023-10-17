// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem1081.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> hash(26, 0);
        vector<bool> st(26, 0);

        for(int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a']++;
        }

        stack<char> stk;
        for(auto e : s)
        {
            if(!st[e - 'a'])
            {
                while(!stk.empty() && stk.top() > e)
                {
                    if(hash[stk.top() - 'a'] > 0)
                    {
                        st[stk.top() - 'a'] = 0;
                        stk.pop(); 
                    }
                    else
                        break;
                }
                st[e - 'a'] = 1;
                stk.push(e);
            }
            hash[e - 'a'] -= 1;
        }

        string res;
        while(!stk.empty())
        {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

