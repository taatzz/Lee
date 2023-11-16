/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 1010;
    int in[N], out[N]; // 统计入度，出度

    // 所有人都信任法官，（有向边指向信任的人），法官不信任任何人，则法官的出度是0
    int findJudge(int n, vector<vector<int>>& trust) {

        for(auto e : trust)
        {
            int a = e[0], b = e[1]; // a->b
            in[b] ++, out[a]++;
        }

        int res = -1;
        for(int i = 1; i <= n; i++)
        {
            if(in[i] == n - 1 && out[i] == 0) res = i;
        }

        return res;
    }
};
// @lc code=end

