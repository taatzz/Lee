#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;


// class Solution {
// public:
//     int scoreOfString(string s) {
//         int n = s.size():

//         int res =0 ;
//         for(int i = 0; i < n - 1; i++)      
//         {
//             res += abs(s[i] - s[i + 1]);
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     static bool cmp(vector<int>& a, vector<int>& b)
//     {
//         return a[0] <= b[0];
//     }

//     int minRectanglesToCoverPoints(vector<vector<int>>& nums, int w) {
//         sort(nums.begin(), nums.end());

//         int n = nums.size();
//         int res = 0;
//         int i = 0;
//         while(i < n)
//         {
//             int start = i;
//             i++;
//             while(i < n && nums[i][0] - nums[start][0] <= w) i++;
//             res ++;
//         }

//         return res;
//     }
// };


class Solution {
public:
    typedef pair<int, int> PII;
    static const int N = 100010;
    int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
    bool st[N];
    vector<int> d;
    unordered_map<int, int> hash;

    void add(int a, int b, int c)
    {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }

    void Dijkstra()
    {
        // memset(d, 0x3f, sizeof d);
        priority_queue<PII, vector<PII>, greater<PII> > q; // 距离，顶点 (pair默认第一个节点进行排序，按照距离排序，堆顶是最小的)
        d[0] = 0;
        
        q.push( {0, 0} );
        
        while(q.size())
        {
            auto t = q.top();
            q.pop();
            
            int dist = t.first, ver = t.second;
            
            if(st[ver]) continue; // 当前顶点的最短路径已经确定
            st[ver] = true; // 当前顶点已经确定
            // 确认当前顶点的联通点的最短路径
            for(int i = h[ver]; i != -1; i = ne[i])
            {
                int j = e[i]; // 联通顶点
                if(dist + w[i] >= hash[j]) continue;
                if(d[j] > dist + w[i])// 当前顶点+距离小于目标顶点的距离
                {
                    d[j] = dist + w[i];// 更新距离
                    q.push({d[j], j}); // 入队
                }
            }
        }

        // 判断目标顶点是否可以到达
    }

    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& nums) {
        memset(h, -1, sizeof h);
        for(auto& e : edges)
        {
            int a = e[0], b = e[1], c = e[2];
            if(a == b) continue;
            add(a, b ,c), add(b, a, c);
        }
        d.resize(n, 0x3f3f3f3f);
        for(int i= 0; i < n; i++) hash[i] = nums[i];

        Dijkstra();
        for(int i = 0; i < n; i++)
            if(d[i] == 0x3f3f3f3f || d[i] >= nums[i]) d[i] = -1;

        return d;
    }
};