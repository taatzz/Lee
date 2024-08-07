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
#include <climits>
#include <iostream>

using namespace std;

// class neighborSum {
// public:

//     vector<vector<int>> nums;
//     int dx[8] = { 0,1,0,-1,1,-1,-1,1};
//     int dy[8] = { 1,0,-1,0,1,1,-1,-1};
//     neighborSum(vector<vector<int>>& grid) {
//         nums = grid;
//     }
    
//     int adjacentSum(int t) {
//         int res = 0;
//         int m = nums.size(), n = nums[0].size();
//         for(int i = 0; i < m; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(nums[i][j] == t)
//                 {
//                     for(int k = 0; k < 4; k++)
//                     {
//                         int a = i + dx[k], b = j + dy[k];
//                         if(a >= 0 && a < m && b >= 0 && b < n)
//                         {
//                             res += nums[a][b];
//                         }
//                     }
//                     return res;
//                 }
//             }
//         }
//     }
    
//     int diagonalSum(int t) {
//         int res = 0;
//         int m = nums.size(), n = nums[0].size();
//         for(int i = 0; i < m; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(nums[i][j] == t)
//                 {
//                     for(int k = 4; k < 8; k++)
//                     {
//                         int a = i + dx[k], b = j + dy[k];
//                         if(a >= 0 && a < m && b >= 0 && b < n)
//                         {
//                             res += nums[a][b];
//                         }
//                     }
//                     return res;
//                 }
//             }
//         }
//     }
// };


// class Solution {
// public:
//     static const int N = 1e5 + 10;
//     int h[N], e[N], ne[N], idx;

//     void add(int a, int b)
//     {
//         e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//     }
//     vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
//         auto bfs = [&]()
//         {
//             queue<int> q;
//             vector<int> dist(n, 0), st(n);
//             q.push(0);

//             while(q.size())
//             {
//                 int t = q.front();
//                 q.pop();

//                 for(int i = h[t]; i != -1; i = ne[i])
//                 {
//                     int j = e[i];
//                     if(!st[j])
//                     {
//                         dist[j] = dist[t] + 1;
//                         q.push(j);
//                         st[j] = 1;
//                     }
//                 }
//             }

//             return dist[n - 1];
//         };
//         for(int i = 0; i < n - 1; i++)
//             {
//                 add(i, i + 1);
//             }

//         vector<int> res;
//         for(auto& e : queries)
//         {
//             int a = e[0], b = e[1];
//             add(a, b);

//             res.push_back(bfs());
//         }

//         return res;
//     }
// };

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<pair<int, int>> h;

        for(int i = 0; i < n - 1; i ++) h.insert({i, i + 1});

        vector<int> res;
        for(auto& e : queries)
        {
            int a = e[0], b = e[1];
            auto it = h.lower_bound({a, -1});
            if(it != h.end() && it->first == a && it->second < b)
            {
                while(it != h.end() && it->first < b)
                {
                    it = h.erase(it);
                }
                h.insert({a, b});
            }
            res.push_back(h.size());
        }

        return res;
    }
};