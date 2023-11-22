/*
 * @lc app=leetcode.cn id=2642 lang=cpp
 *
 * [2642] 设计可以求最短路径的图类
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

class Graph {
public:
    static const int M = 6010, N = 110;
    int h[N], e[M], ne[M], w[M], idx = 0;
    int d[N];
    bool st[N];

    void add(int a, int b, int c)
    {
        e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    }

    void Dijkstra(int x)
    {
        memset(d, 0x3f, sizeof d);
        memset(st, 0, sizeof st);
        priority_queue<PII, vector<PII>, greater<PII> > q;
        d[x] = 0;
        q.push(pair<int, int>( 0, x ));

        while(q.size())
        {
            PII t = q.top();
            q.pop();
            
            int dist = t.first, ver = t.second;
            
            if(st[ver]) continue; // 当前顶点的最短路径已经确定
            st[ver] = true; // 当前顶点已经确定
            // 确认当前顶点的联通点的最短路径
            for(int i = h[ver]; i != -1; i = ne[i])
            {
                int j = e[i]; // 联通顶点
                if(d[j] > dist + w[i])// 当前顶点+距离小于目标顶点的距离
                {
                    d[j] = dist + w[i];// 更新距离
                    q.push(pair<int, int>(d[j], j)); // 入队
                }
            }
        }
    }

    Graph(int n, vector<vector<int> >& edges) {
        memset(h, -1, sizeof h);
        for(vector<int> e : edges)
        {
            int a = e[0], b = e[1], c = e[2];
            add(a, b, c);
        }
    }
    
    void addEdge(vector<int> edge) {
        int a = edge[0], b = edge[1], w = edge[2];
        add(a, b, w);
    }
    
    int shortestPath(int node1, int node2) {

        Dijkstra(node1);

        if(d[node2] == 0x3f3f3f3f) return -1;
        else return d[node2];
    }
};
/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
// @lc code=end

