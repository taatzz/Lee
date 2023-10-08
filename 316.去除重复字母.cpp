/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> hash(26, 0), st(26, 0);

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
                stk.push(e);
                st[e - 'a'] = 1;
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

