/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
#include <vector>

using namespace std;

// class Solution {
// public:

//     void dfs(vector<vector<int> >& g, vector<int>& s, int n, int i)
//     {
//         for(int j = 0; j < n; j++)
//         {
//             if(g[i][j] == 1 && !s[j])
//             {
//                 s[j] = 1;
//                 dfs(g, s, n, j);
//             }
//         }
//     }

//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();

//         vector<int> st(n, 0);

//         int res = 0;
//         for(int i = 0; i < n; i++)
//         {
//             if(!st[i])
//             {
//                 dfs(isConnected, st, n, i);
//                 res++;
//             }
//         }

//         return res;
//     }
// };

class Solution {
public:

    // 并查集
    int find(vector<int>& p, int x)
    {
        if(x != p[x])
            p[x] = find(p, p[x]);
        return p[x];
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> p(n);
        for(int i = 0; i < n; i++)
            p[i] = i;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j] == 1)
                    p[find(p, i)] = find(p, j);
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(p[i] == i)
                res++;
        }

        return res;
    }
};
// @lc code=end

