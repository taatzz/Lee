/*
 * @lc app=leetcode.cn id=2434 lang=cpp
 *
 * [2434] 使用机器人打印字典序最小的字符串
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        unordered_map<int, int> h;
        for(int i = 0; i < n; i++) h[s[i] - 'a']++;

        stack<int> st;
        string res;
        for(int i = 0; i < n; i++)
        {
            while(st.size() && s[st.top()] <= s[i]) 
            {
                bool flag = false;
                // 后续如果存在更小的元素就没必要出栈，要等待后续的元素出栈
                for(int i = 0; i < s[st.top()] - 'a'; i++)
                {
                    if(h[i] != 0) 
                    {
                        flag = true;
                        break;
                    }
                }
                if(flag) break;

                res += s[st.top()];
                st.pop();
            }
            st.push(i);
            h[s[i] - 'a']--;
        }

        while(st.size())
        {
            res += s[st.top()];
            st.pop();
        }

        return res;
    }
};
// @lc code=end

