/*
 * @lc app=leetcode.cn id=1079 lang=cpp
 *
 * [1079] 活字印刷
 */

// @lc code=start
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 10;
    bool st[N];
    int res = 0;

    void get(string s, int x)
    {
        int n = s.size();

        for(int i = 0; i < n; i++)
        {
            if(i > 0 && st[i - 1] == 0 && s[i] == s[i - 1]) continue;
            if(!st[i])
            {
                res ++;
                st[i] = 1;
                get(s, x + 1);
                st[i] = 0;
            }
        }
    }

    int numTilePossibilities(string s) {
        // 排序判重
        sort(s.begin(), s.end());
        get(s, 0);

        return res;
    }
};
// @lc code=end

