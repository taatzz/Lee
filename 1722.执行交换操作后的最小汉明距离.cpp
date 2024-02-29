/*
 * @lc app=leetcode.cn id=1722 lang=cpp
 *
 * [1722] 执行交换操作后的最小汉明距离
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int h[N], e[N * 2], ne[N * 2], idx;
    bool st[N];
    vector<vector<int>> t;
    int cnt = 0;

    void dfs(vector<int>& tmp, int u)
    {
        tmp.push_back(u);
        st[u] = true;

        for(int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!st[j])
            {
                dfs(tmp, j);
            }
        }
    }


    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        memset(h, -1, sizeof h);
        for(auto& e : allowedSwaps)
        {
            int a = e[0], b = e[1];
            add(a, b), add(b, a);
        }

        for(int i = 0; i < source.size(); i++)
        {
            if(!st[i])
            {
                vector<int> tmp;
                dfs(tmp, i);
                t.push_back(tmp);
            }
        }

        int res = 0;
        for(int i = 0; i < t.size(); i++)
        {
            unordered_map<int, int> h1, h2;
            for(int j = 0; j < t[i].size(); j++)
            {
                h2[target[t[i][j]]]++;
            }

            for(int j = 0; j < t[i].size(); j++)
            {
                int e = source[t[i][j]];
                if(h2.find(e) != h2.end()) 
                {
                    res++;
                    h2[e]--;
                    if(h2[e] == 0) h2.erase(e);
                }
            }
        }

        return source.size() - res;
    }
};
// @lc code=end

