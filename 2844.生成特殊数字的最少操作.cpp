/*
 * @lc app=leetcode.cn id=2844 lang=cpp
 *
 * [2844] 生成特殊数字的最少操作
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 枚举以 25,50,75,00 结尾的数字
    int minimumOperations(string s) {
        int i = 0, n = s.size();

        int res = INT_MAX;
        unordered_map<char, char> h;
        h['2'] = '5';
        h['5'] = '0';
        h['0'] = '0';
        h['7'] = '5';

        bool flag = 0;
        for(; i < n; i++)
        {
            if(s[i] == '0') flag = 1;
            if(h.count(s[i]))
            {
                int j = i + 1;
                for(; j < n; j++)
                {
                    if(s[j] == h[s[i]])
                    {
                        res = min(res, n - i - 2);
                        break;
                    }
                }
            }
        }
        // 没有上面结尾的情况那么就只能看有没有0，将0之外的全部删除
        if(res == INT_MAX && flag) res = n - 1; 
        else if(res == INT_MAX) res = n; // 否则全删

        return res;
    }
};
// @lc code=end

