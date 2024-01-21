#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <queue>

using namespace std;

// T1
// class Solution {
// public:
//     int minimumPushes(string s) {
//         int n = s.size();
        
//         if(n <= 8) return n;
//         else if(n > 8 && n <= 16)
//         {
//             int res = 8;
//             res += (n - 8) * 2;
//             return res;
//         }
//         else if(n > 16 && n <= 24)
//         {
//             int res = 24;
//             res += (n - 16) * 3;
//             return res;
//         }
//         else
//         {
//             int res = 48;
//             res += (n - 24) * 4;
//             return res;
//         }
//         return 0;
//     }
// };

// T2
class Solution {
public:
    static const int N = 110;
    int g[N][N];

    void floyd(int n)
    {
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    }
    
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> res(n);
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(i == j) g[i][j] = 0;
                else g[i][j] = 1000;
        
        for(int i = 1; i <= n - 1; i++)
            g[i][i + 1] = g[i + 1][i] = 1;
        g[x][y] = g[y][x] = 1;
        
        floyd(n);

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(i != j && g[i][j] < 1000 / 2) res[g[i][j] - 1]++;

        return res;
    }
};


// T3
// class Solution {
// public:
//     int cnt[30];
    
//     int minimumPushes(string s) {
//         int n = s.size();
        
//         for(int i = 0; i < n; i++) cnt[s[i] - 'a'] ++;
//         priority_queue<int, vector<int>, less<int>> q;
        
//         for(int i = 0; i < 26; i++)
//             if(cnt[i]) q.push(cnt[i]);
        
//         int t = 1, x = 1, res = 0;
//         while(q.size())
//         {
//             if(x <= 8) t = 1;
//             else if(x >= 9 && x <= 16) t = 2;
//             else if(x >= 17 && x <= 24) t = 3;
//             else t = 4;
//             res += q.top() * t;
//             q.pop();
//             x++;
//         }
        
//         return res;
//     }
// };