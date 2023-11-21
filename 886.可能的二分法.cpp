/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

// @lc code=start
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 10010;
    int h[N], e[N], ne[N], color[N], idx = 0;
    bool st[N];

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    bool dfs(int t, int c)
    {
        color[t] = c;
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!color[j])
            {
                if(!dfs(j, 3 - c)) return false;
            }
            else if(color[j] == c) return false;
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        memset(h, -1, sizeof h);
        for(auto e : dislikes)
        {
            int a = e[0], b = e[1];
            add(a, b), add(b, a);
        }

        bool flag = 1;
        for(int i = 1; i <= n; i++)
        {
            if(!color[i])
            {
                if(!dfs(i, 1))
                {
                    flag = 0;
                }
            }
        }

        return flag;
    }
};
// @lc code=end

