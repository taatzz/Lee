// @before-stub-for-debug-begin
#include <vector>
#include <string>
//#include "commoncppproblem647.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        vector<vector<int>> f(n, vector<int>(n));

        f[0][0] = 1;
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            f[i][i] = 1;
            res += f[i][i];
            for(int j = i - 1; j >= 0; j--)
            {
                if(s[i] == s[j])
                {
                    if(i - j <= 1)
                    {
                        res++;
                        f[i][j] = 1;
                    }
                    else if(f[i - 1][j + 1])
                    {
                        res++;
                        f[i][j] = 1;
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end

