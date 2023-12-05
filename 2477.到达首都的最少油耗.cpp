/*
 * @lc app=leetcode.cn id=2477 lang=cpp
 *
 * [2477] 到达首都的最少油耗
 */

// @lc code=start
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int h[N], e[N * 2], ne[N * 2], idx = 0;
    bool st[N];
    int _seats;
    long long res = 0;

    void add(int a,int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    int dfs(int x)
    {
        int size = 1;
        st[x] = 1;

        for(int i = h[x]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(st[j]) continue;
            size += dfs(j);
        }

        if(x)
        {
            res += (_seats + size - 1) / _seats;
        }

        return size;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        _seats = seats;
        memset(h, -1, sizeof h);
        for(auto e : roads)
        {
            add(e[0], e[1]), add(e[1], e[0]);
        }

        for(int i = h[0]; i != -1; i = ne[i])
        {
            int j = e[i];
            int distance = dfs(j);
        }

        return res;
    }
};
// @lc code=end

