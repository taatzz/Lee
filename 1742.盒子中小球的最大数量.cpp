/*
 * @lc app=leetcode.cn id=1742 lang=cpp
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int cnt[50];

    void dfs(string& s, int x, int sum, bool is_limit, int c)
    {
        int n = s.size();
        if(x == n)
        {
            cnt[sum] += 1 * c;
            return;
        }

        int hi = is_limit ? s[x] - '0' : 9;
        for(int i = 0; i <= hi; i++)
        {
            dfs(s, x + 1, sum + i, is_limit && hi == i, c);
        }

    }


    int countBalls(int lowLimit, int highLimit) {
        string low = to_string(lowLimit - 1), high = to_string(highLimit);

        dfs(low, 0, 0, true, 1);
        dfs(high, 0, 0, true, -1);


        int res = 0;
        for(int i = 0; i < 50; i++) 
            if(cnt[i] < 0) res = max(res, abs(cnt[i]));

        return res;
    }
};
// @lc code=end

