/*
 * @lc app=leetcode.cn id=2696 lang=cpp
 *
 * [2696] 删除子串后的字符串最小长度
 */

// @lc code=start
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        int n = s.size();

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'B')
            {
                if(!st.empty() && st.top() == 'A')
                    st.pop();
                else st.push(s[i]);
            }
            else if(s[i] == 'D')
            {
                if(!st.empty() && st.top() == 'C')
                    st.pop();
                else st.push(s[i]);
            }
            else st.push(s[i]);
        }

        return st.size();
    }
};
// @lc code=end

