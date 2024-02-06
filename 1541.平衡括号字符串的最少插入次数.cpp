/*
 * @lc app=leetcode.cn id=1541 lang=cpp
 *
 * [1541] 平衡括号字符串的最少插入次数
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size(), cnt = 0;

        vector<char> st;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(') st.push_back('(');
            else
            {
                if(st.size() == 0)
                {
                    if(i + 1 < n && s[i + 1] == ')')
                    {
                        cnt += 1;
                        i++;
                    }
                    else cnt += 2;
                }
                else
                {
                    if(i + 1 < n && s[i + 1] == ')')
                        i++;
                    else
                        cnt += 1;
                    st.pop_back();
                }
            }
        }

        // 最后栈里边之后剩下左括号
        return cnt + st.size() * 2;
    }
};
// @lc code=end

