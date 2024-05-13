/*
 * @lc app=leetcode.cn id=1632 lang=cpp
 *
 * [1632] 矩阵转换后的秩
 */

// @lc code=start
#include <vector>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

class Solution {
public:
    static const int N = 250010;
    int dist[N];
    int h[N], e[N], ne[N], in[N], idx;
    int p[N];

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    int find(int x)
    {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void topsort(vector<vector<int>>& nums)
    {
        int m = nums.size(), n = nums[0].size();
        queue<int> q;
        for(int i = 0; i < n * m; i++)
            if(find(i) == i && !in[i]) 
            {
                q.push(i);
            }

        while(q.size())
        {
            int t = q.front();
            q.pop();

            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
               
                if(-- in[j] == 0)
                {
                    dist[j] = dist[t] + 1;
                    q.push(j);
                }
            }
        }
    }

    // 每一行每一列相同的元素合并到同一个并查集中，题目中的转换顺序就是拓扑排序的顺序，所以我们让小数根向大数根连有向边
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();
        memset(h, -1, sizeof h);
        for(int i = 0; i <= m * n; i++) p[i] = i, dist[i] = 1;

        for(int i = 0; i < m; i++)
        {
            map<int, vector<int>> h;
            for(int j = 0; j < n; j++)
                h[nums[i][j]].emplace_back(i * n + j);
            
            for(auto& [k, e] : h)
                for(int j = 0; j < e.size(); j++)
                {
                    if(j + 1 < e.size())
                    {
                        int a = find(e[j]), b = find(e[j + 1]);
                        if(a != b) p[a] = b;
                    }
                }
        }

        for(int j = 0; j < n; j++)
        {
            map<int, vector<int>> h;
            for(int i = 0; i < m; i++)
                h[nums[i][j]].emplace_back(i * n + j);
            
            for(auto& [k, e] : h)
                for(int i = 0; i < e.size(); i++)
                {
                    if(i + 1 < e.size())
                    {
                        int a = find(e[i]), b = find(e[i + 1]);
                        if(a != b) p[a] = b;
                    }
                }
        }

        for(int i = 0; i < m; i++)
        {
            vector<pair<int, int>> t;
            for(int j = 0; j < n; j++)
            {
                t.emplace_back(nums[i][j], j);
            }
            // 排序去重，只连并查集的根
            sort(t.begin(), t.end());
            for(int j = 0; j + 1 < t.size(); j++)
            {
                if(t[j].first != t[j + 1].first)
                {
                    int a = find(i * n + t[j].second), b = find(i * n + t[j + 1].second);
                    add(a, b);
                    in[b]++;
                }
            }
        }

        for(int j = 0; j < n; j++)
        {
            vector<pair<int, int>> t;
            for(int i = 0; i < m; i++) t.emplace_back(nums[i][j], i);
            sort(t.begin(), t.end());
            for(int i = 0; i + 1 < t.size(); i++)
            {
                if(t[i].first != t[i + 1].first)
                {
                    int a = find(t[i].second * n + j), b = find(t[i + 1].second * n + j);
                    add(a, b);
                    in[b]++;
                }
            }
        }

        topsort(nums);

        vector<vector<int>> res(m, vector<int>(n));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++) res[i][j] = dist[find(i * n + j)];
        }

        return res;
    }
};
// @lc code=end

