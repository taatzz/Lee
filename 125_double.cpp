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

// T1
// class Solution {
// public:
//     int minOperations(vector<int>& nums, int k) {
//         int res = 0;
//         for(auto e : nums)
//         {
//             if(e < k) res++;
//         }

//         return res;
//     }
// };

// T2
// class Solution {
// public:
//     int minOperations(vector<int>& nums, int k) {
//         priority_queue<long long, vector<long long>, greater<long long>> q(nums.begin(), nums.end());
//         int res = 0;

//         while(q.top() < k && q.size() >= 2)
//         {
//             int num1 = q.top();
//             q.pop();
//             int num2 = q.top();
//             q.pop();

//             q.push((long long)min(num1, num2) * 2 + max(num1, num2));
//             res++;
//         }

//         return res;
//     }
// };

// T3
// class Solution {
// public:
//     static const int N = 1010;
//     int h[N], w[N * 2], e[N * 2], ne[N * 2], idx;
//     bool st[N];
//     int k;

//     void add(int a, int b, int c)
//     {   
//         e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
//     } 

//     void dfs(int u, int c, int& cnt)
//     {
//         st[u] = true;
//         if(c % k == 0) cnt += 1;

//         for(int i = h[u]; i != -1; i = ne[i])
//         {
//             int j = e[i];
//             if(st[j]) continue;
//             dfs(j, c + w[i], cnt);
//         }
//     }

//     vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
//         int n = edges.size() + 1;
//         k = signalSpeed;
//         memset(h, -1, sizeof h);
//         for(auto& e : edges)
//         {
//             int a = e[0], b = e[1], c = e[2];
//             add(a, b, c), add(b, a, c);
//         }

//         vector<int> res(n);
//         for(int i = 0; i < n; i++)
//         {
//             memset(st, 0, sizeof st);
//             int sum = 0;
//             st[i] = true;
//             for(int j = h[i]; j != -1; j = ne[j])
//             {
//                 int x = 0;
//                 dfs(e[j], w[j], x);
//                 res[i] += x * sum;
//                 sum += x;
//             }
//         }

//         return res;
//     }
// };