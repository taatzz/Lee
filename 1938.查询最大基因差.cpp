/*
 * @lc app=leetcode.cn id=1938 lang=cpp
 *
 * [1938] 查询最大基因差
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int h[N], e[N], ne[N], idx;
    int son[32 * N][2], j, cnt[N * 32];
    vector<int> res;
    unordered_map<int, vector<pair<int,int>>> hash;

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    void insert(int x)
    {
        int p = 0;
        for(int i = 31; i >= 0; i--)
        {
            int u = (x >> i & 1);
            if(!son[p][u]) son[p][u] = ++j;
            p = son[p][u];
            cnt[p]++;
        }
    }

    int query(int x)
    {
        int p = 0;
        int res = 0;
        for(int i = 31; i >= 0; i--)
        {
            int u = (x >> i & 1);
            if(son[p][!u])
            {
                res += (1 << i);
                p = son[p][!u];
            }
            else p = son[p][u];
        }

        return res;
    }

    void remove(int x)
    {
        int p = 0;
        for(int i = 31; i >= 0; i--)
        {
            int u = (x >> i & 1);
            if(--cnt[son[p][u]] == 0)
            {
                son[p][u] = 0;
                return;
            }
            p = son[p][u];
        }
    }

    // dfs更新一条路径上查询
    void dfs(int u)
    {
        insert(u);
        if(hash.count(u))
        {
            for(auto& e : hash[u])
            {
                res[e.second] = query(e.first);
            }
        }

        for(int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            dfs(j);
        }
        remove(u);
    }

    // 对于每一条路径上的点，如果查询点在当前路径上更新查询答案
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size();
        memset(h, -1, sizeof h);
        res.resize(queries.size());
        int root = 0;
        for(int i = 0; i < n; i++)
        {
            if(parents[i] == -1) 
            {
                root = i;
                continue;
            }
            add(parents[i], i);
        }
        
        // 离线查询
        for(int i = 0; i < queries.size(); i++)  
            hash[queries[i][0]].emplace_back(queries[i][1], i);
        
        insert(root);
        for(auto& e : hash[root])
        {
            res[e.second] = query(e.first);
        }
        for(int i = h[root]; i != -1; i = ne[i])
        {
            int j = e[i];
            dfs(j);
        }

        return res;
    }
};
// @lc code=end

