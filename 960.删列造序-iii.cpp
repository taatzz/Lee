/*
 * @lc app=leetcode.cn id=960 lang=cpp
 *
 * [960] 删列造序 III
 */

// @lc code=start
#include <vector>
#include <string>
#include <cstring>
#include <functional>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();

        vector<int> st(m);
        int mem[m + 1][m + 1];
        memset(mem, -1, sizeof mem);
        function<int(int, int)> dfs = [&](int x, int pre)->int
        {
            if(x == m)
            {
                return 0;
            }
            if(pre != -1 && mem[x][pre] != -1) return mem[x][pre];

            int res = INT_MIN;
            bool flag = 1;
            if(pre != -1)
                for(int i = 0; i < n; i++)
                    if(strs[i][x] < strs[i][pre]) flag = 0;

            if(pre == -1 || flag)
            {
                res = max(res, dfs(x + 1, x) + 1);
            }
            res = max(res, dfs(x + 1, pre));
            if(pre != -1) mem[x][pre] = res;

            return res;
        };

        return m - dfs(0, -1);
    }
};
// @lc code=end

