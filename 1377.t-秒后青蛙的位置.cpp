/*
 * @lc app=leetcode.cn id=1377 lang=cpp
 *
 * [1377] T 秒后青蛙的位置
 */

// @lc code=start
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
public:
    typedef pair<int, double> PID;
    static const int N = 150;
    int h[N], e[N * 2], ne[N * 2], idx, in[N];
    bool st[N];
    double dist[N];
    int _target, k;

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    double bfs()
    {
        queue<int> q;
        q.push(1);
        st[1] = 1;
        dist[1] = 1;
        int time = 0;

        while(q.size() && time < k)
        {
            int n = q.size();
            while(n --)
            {
                auto t = q.front();
                q.pop();

                int cnt = 0;
                double pro = dist[t];
                for(int i = h[t]; i != -1; i = ne[i]) 
                {
                    int j = e[i];
                    if(!st[j]) cnt++;
                }
                if(t == _target && cnt) return 0;

                for(int i = h[t]; i != -1; i = ne[i])
                {
                    int j = e[i];
                    if(!st[j])
                    {
                        dist[j] = pro * (double)1 / cnt;
                        st[j] = 1;
                        q.push(j);
                    }
                }
            }
            time ++;
        }

        return dist[_target];
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        _target = target, k = t;
        memset(h, -1, sizeof h);

        for(auto& e : edges)
        {
            int a = e[0], b = e[1];
            add(a, b), add(b, a);
        }

        return bfs();
    }
};
// @lc code=end

