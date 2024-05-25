/*
 * @lc app=leetcode.cn id=1003 lang=cpp
 *
 * [1003] 检查替换后的词是否有效
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        int n = s.size();

        for(int i = 0; i < n; i++)
        {
            bool flag = 0;
            if(s[i] == 'c')
            {
                int n = stk.size();
                if(stk.size() >= 2 && stk[n - 1] == 'b' && stk[n - 2] == 'a')
                {
                    flag = 1;
                    stk.pop_back();
                    stk.pop_back();
                }
            }
            if(!flag) stk.push_back(s[i]);
        }

        return stk.size() == 0;
    }
};
// @lc code=end

