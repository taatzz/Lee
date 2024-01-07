/*
 * @lc app=leetcode.cn id=2211 lang=cpp
 *
 * [2211] 统计道路上的碰撞次数
 */

// @lc code=start
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int countCollisions(string s) {
        int n = s.size(), res = 0;
        stack<char> st;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'R') st.push(s[i]);
            else if(s[i] == 'L')
            {
                if(!st.empty())
                {
                    if(st.top() == 'R')
                    {
                        st.pop();
                        res+=2;
                        st.push('S');
                    }
                    else if(st.top() == 'S')
                        res++;
                }
            }
            else st.push(s[i]);
        }

        while(!st.empty())
        {
            if(st.top() == 'S')
            {
                st.pop();
                while(!st.empty() && st.top() != 'S')
                {
                    res++;
                    st.pop();
                }
            }
            else st.pop();
        }

        return res;
    }
};
// @lc code=end

