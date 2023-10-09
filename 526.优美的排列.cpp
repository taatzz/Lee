/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int res = 0;

    void dfs(vector<int>& s, int x)
    {
        if(x == s.size())
        {
            res++;
            return;
        }

        for(int i = 1; i < s.size(); i++)
        {
            if(!s[i] && (!(i % x)|| !(x % i)))
            {
                s[i] = 1;
                dfs(s, x + 1);
                s[i] = 0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int> st(n + 1, 0);
        vector<int> path(n + 1, 0);

        dfs(st, 1);

        return res;
    }
};
// @lc code=end

