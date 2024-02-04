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
//     int returnToBoundaryCount(vector<int>& nums) {
//         int n = nums.size();

//         int sum = 0, res = 0;;
//         for(int i = 0; i < n; i++)
//         {
//             sum += nums[i];
//             if(sum == 0)res++;
//         }   

//         return res;   
//     }
// };

// T2、4
// class Solution {
// public:
//     typedef unsigned long long ULL;
//     static const int N = 100010, P = 131;
//     ULL h[N], p[N];

//     ULL get(int l, int r)
//     {
//         return h[r] - h[l - 1] * p[r - l + 1];
//     }

//     int minimumTimeToInitialState(string s, int k) {
//         p[0] = 1;

//         int n = s.size();
//         for(int i = 1; i <= n; i++)
//         {
//             h[i] = h[i - 1] * P + s[i - 1];
//             p[i] = p[i - 1] * P;
//         }

//         for(int i = k; i < n; i += k)
//         {
//             int len = n - i;
//             if(get(1, len) == get(i + 1, n)) return i / k;
//         }

//         return (n + k - 1) / k;
//     }
// };


class Solution {
public:
    static const int N = 510;
    int s[N][N];
    int st[N][N];
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    int dist[N][N];
    int res[N][N];

    void insert1(int x1, int y1, int c)
    {
        int x2 = x1 + 3 - 1, y2 = y1 + 3 - 1;
        dist[x1][y1] += c;
        dist[x2 + 1][y1] -= c;
        dist[x1][y2 + 1] -= c;
        dist[x2 + 1][y2 + 1] += c;
    }
    
    void insert2(int x1, int y1, int c)
    {
        int x2 = x1 + 3 - 1, y2 = y1 + 3 - 1;
        res[x1][y1] += c;
        res[x2 + 1][y1] -= c;
        res[x1][y2 + 1] -= c;
        res[x2 + 1][y2 + 1] += c;
    }

    bool check(vector<vector<int>>& nums, int x, int y, int k)
    {
        queue<pair<int, int>> q;
        int m = min((int)nums.size(), x + 3 - 1), n = min((int)nums[0].size(), y + 3 - 1);
        for(int i = x; i <= m; i++)
        {
            for(int j = y; j <= n; j++)
                q.push({i, j});
        }

        while(q.size())
        {
            auto t = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int a = t.first + dx[i], b = t.second + dy[i];
                if(a >= x && a <= m && b >= y && b <= n)
                {
                    if(abs(nums[a][b] - nums[t.first][t.second]) > k)
                        return false;
                }
            }
        }

        return true;
    }

    vector<vector<int>> resultGrid(vector<vector<int>>& nums, int k) {
        int m = nums.size(), n = nums[0].size();

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + nums[i - 1][j - 1];

        for(int i = 0; i <= m - 3; i++)
        {
            for(int j = 0; j <= n - 3; j++)
            {
                if(check(nums, i, j, k)) 
                {
                    int x = i + 3, y = j + 3;
                    insert1(i + 1, j + 1, 1);
                    insert2(i + 1, j + 1, (s[x][y] - s[x][j] - s[i][y] + s[i][j]) / 9);
                }
            }
        }
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dist[i][j] += dist[i - 1][j] + dist[i][j - 1] - dist[i - 1][j - 1];
                res[i][j] += res[i - 1][j] + res[i][j - 1] - res[i - 1][j - 1];
            }
        }

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(dist[i][j] <= 0)
                {
                    res[i][j] = nums[i - 1][j - 1];
                }
                else
                {
                    res[i][j] = res[i][j] / dist[i][j];
                }
            }
        }

        vector<vector<int>> ans(m, vector<int>(n));

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                ans[i][j] = res[i + 1][j + 1];

        return ans;
    }
};