/*
 * @lc app=leetcode.cn id=2092 lang=cpp
 *
 * [2092] 找出知晓秘密的所有专家
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
    int dist[N];
    bool st[N];
    unordered_set<int> hash;

    void add(int a, int b, int c)
    {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }

    void bfs(int u)
    {
        queue<int> q;
        q.push(0);
        q.push(u);

        while(q.size())
        {
            int t = q.front();
            q.pop();

            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i], c = w[i];
                if(c < dist[t]) continue;
                if(c < dist[j]) dist[j] = c, q.push(j);
                if(!hash.count(j))
                    hash.insert(j);
            }
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        memset(h, -1, sizeof h);
        memset(dist, 0x3f, sizeof dist);
        for(auto& e : meetings)
        {
            int a = e[0], b = e[1], c = e[2];
            add(a, b, c);
            add(b, a, c);
        }

        dist[0] = 0, dist[firstPerson] = 0;
        hash.insert(0), hash.insert(firstPerson);
        bfs(firstPerson);

        vector<int> res;
        for(auto& e : hash) res.push_back(e);
        sort(res.begin(), res.end());
        
        return res;
    }
};
// @lc code=end

