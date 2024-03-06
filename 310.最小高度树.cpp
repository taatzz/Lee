/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:
    static const int N = 20010;
    int h[N], e[N * 2], ne[N * 2], in[N], idx;
    int high = INT_MAX;
    vector<int> res;

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    vector<int> bfs(int n)
    {
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(in[i] == 1) q.push(i);
        }

        vector<int> res;
        while(q.size())
        {
            vector<int> tmp;
            int size = q.size();
            while(size--)
            {
                int t = q.front();
                q.pop();

                tmp.push_back(t);
                for(int i = h[t]; i != -1; i = ne[i])
                {
                    int j = e[i];
                    if(-- in[j] == 1)
                    {
                        q.push(j);
                    }
                }
            }
            res.clear();
            res = tmp;
        }

        return res;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        memset(h, -1, sizeof h);
        for(auto& e : edges)
        {
            int a = e[0], b = e[1];
            add(a, b), add(b, a);
            in[a]++, in[b]++;
        }

        return bfs(n);
    }
};
// @lc code=end

