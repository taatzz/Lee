/*
 * @lc app=leetcode.cn id=2581 lang=cpp
 *
 * [2581] 统计可能的树根数目
 */

// @lc code=start
#include <cstring>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int h[N], e[N * 2], ne[N * 2], idx;
    bool st[N];
    int cnt = 0, ans = 0;
    unordered_set<long long> hash;

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    void dfs(int u)
    {
        st[u] = 1;
        for(int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!st[j])
            {
                if(hash.count((long long) u << 32 | j)) 
                {
                    cnt++;
                }
                dfs(j);
            }
        }
    }

    void reroot(int u, int k, int pre)
    {
        st[u] = 1;
        ans += pre >= k;
        for(int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!st[j])
            {
                int tmp = pre - hash.count((long long) u << 32 | j) + hash.count((long long) j << 32 | u);
                reroot(j, k, tmp);
            }
        }
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        memset(h, -1, sizeof h);
        for(auto& e : edges)
        {
            int a = e[0], b = e[1];
            add(a, b), add(b, a);
        }
        for(auto& e : guesses)
        {
            hash.insert((long long) e[0] << 32 | e[1]);
        }

        dfs(0);
        memset(st, 0, sizeof st);
        reroot(0, k, cnt);

        return ans;
    }
};
// @lc code=end

