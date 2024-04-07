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
//     int longestMonotonicSubarray(vector<int>& nums) {
//         int n = nums.size();

//         int res = 1;
//         for(int i = 0; i < n; i++)    
//         {
//             for(int j = i - 1; j >= 0; j--)
//             {
//                 if(nums[j] < nums[j + 1]) 
//                 {
//                     res = max(res, i - j + 1);
//                 }
//                 else break;
//             }
//         }

//         for(int i = 0; i < n; i++)    
//         {
//             for(int j = i - 1; j >= 0; j--)
//             {
//                 if(nums[j] > nums[j + 1]) 
//                 {
//                     res = max(res, i - j + 1);
//                 }
//                 else break;
//             }
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     string getSmallestString(string s, int k) {
//         int n = s.size();

//         for(int i = 0; i < n; i++)      
//         {
//             int x = min(s[i] - 'a', 'z' - s[i] + 1);
//             if(x <= k) 
//             {
//                 s[i] = 'a';
//                 k -= x;
//             }
//             else
//             {
//                 char c = s[i] - k;
//                 s[i] = c;
//                 k = 0;
//             }
//         }

//         return s;
//     }
// };

// class Solution {
// public:
//     long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
        
//         int n = nums.size();
//         int m = n / 2;
        
//         long long res =0 ;
//         for(int i = 0; i < n; i++)
//         {
//             if(i < m)
//             {
//                 if(nums[i] > k) res += nums[i] - k; 
//             }
//             else if(i == m) res += abs(nums[i] - k);
//             else
//             {
//                 if(nums[i] < k) res += k - nums[i];
//             }
//         }
        
//         return res;
//     }
// };


class Solution {
public:
    static const int N = 100010;
    int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
    bool st[N];
    unordered_map<int, int> hash;
    int p[N];

    void add(int a, int b, int c)
    {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }

    int find(int x)
    {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    void bfs(int x)
    {
        queue<int> q;
        q.push(x);
        st[x] = 1;

        int res = INT_MAX;
        while(q.size())
        {
            auto t = q.front();
            q.pop();

            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                res &= w[i];
                if(!st[j]) 
                {
                    q.push(j);
                    st[j] = 1;
                }
            }
        }

        hash[x] = res;
    }
    // 因为可以重复经过路径所以我们应该经过每一条路径那样答案最小同时经过同一条路不影响答案。
    // 并查集维护连通性，bfs寻找每一个连通块的最小值，如果两个地点没在一个连通块则无法到达
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        for(int i = 0; i <= n; i++) p[i] = i;
        memset(h, -1, sizeof h);
        for(auto& e : edges)
        {
            int a = e[0], b = e[1], c = e[2];
            add(a, b, c), add(b, a, c);
            a = find(a), b = find(b);
            if(a != b) p[a] = b;
        }

        for(int i = 0; i < n; i++)
        {
            if(p[i] == i)
            {
                bfs(i);
            }
        }

        vector<int> res;
        for(auto& e : query)
        {
            int a = e[0], b = e[1];
            if(a == b) 
            {
                res.push_back(0);
                continue;
            }
            a = find(a), b = find(b);
            if(a != b) res.push_back(-1);
            else res.push_back(hash[a]);
        }

        return res;
    }
};