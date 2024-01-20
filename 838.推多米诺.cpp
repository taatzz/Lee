/*
 * @lc app=leetcode.cn id=838 lang=cpp
 *
 * [838] 推多米诺
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    // 判断连续的'.'的左右的情况
    string pushDominoes(string s) {
        int n = s.size();

        int i = 0;
        while(i < n)
        {
            if(s[i] == '.')
            {
                int end = i;
                while(end + 1 < n && s[end + 1] == '.') end++;
                char l = i - 1 > -1 ? s[i - 1] : 'L';
                char r = end + 1 < n ? s[end + 1] : 'R';
                if(l == r) 
                    for(int j = i; j <= end; j++) s[j] = l;
                else if(l == 'R' && r == 'L')
                {
                    int d = (end - i + 1) / 2;
                    for(int j = 0; j < d; j++)
                    {
                        s[i + j] = 'R';
                        s[end - j] = 'L';
                    }
                }
                i = end + 1;
            }
            else i++;
        }

        return s;
    }
};
// @lc code=end

