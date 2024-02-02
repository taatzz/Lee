/*
 * @lc app=leetcode.cn id=1239 lang=cpp
 *
 * [1239] 串联字符串的最大长度
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int res = 0;

    // x 当前匹配位置，flag当前已经匹配的字符的二进制表示，cur匹配的长度
    void dfs(vector<string>& a, int x, int flag, int cur)
    {
        int n = a.size();
        if(x >= n) 
        {
            res = max(res, cur);
            return;
        }

        // 不选
        dfs(a, x + 1, flag, cur);

        int f = 0;
        for(int i = 0; i < a[x].size(); i++)
        {
            // 当前字符有重叠不选
            if(f & (1 << (a[x][i] - 'a'))) return;

            f |= (1 << (a[x][i] - 'a'));
        }

        // 和前面选的没有冲突才选
        if(!(f & flag))
            dfs(a, x + 1, f + flag, cur + a[x].size());
    }

    int maxLength(vector<string>& arr) {
        dfs(arr, 0, 0, 0);

        return res;
    }
};
// @lc code=end

