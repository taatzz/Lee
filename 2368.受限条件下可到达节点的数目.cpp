/*
 * @lc app=leetcode.cn id=2368 lang=cpp
 *
 * [2368] 受限条件下可到达节点的数目
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<int> hash;
    static const int N = 100010;
    int h[N], e[N * 2], ne[N * 2], idx;
    bool st[N];
    int res = 0;

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    void dfs(int u)
    {
        st[u] = true;
        res++;

        for(int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!st[j] && hash.find(j) == hash.end())
            {
                dfs(j);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& nums) {
        memset(h, -1, sizeof h);
        for(auto& e : nums)
        {
            hash.insert(e);
        }

        for(auto& e : edges)
        {
            int a = e[0], b = e[1];
            add(a, b), add(b, a);
        }
        dfs(0);

        return res;
    }
};
// @lc code=end

