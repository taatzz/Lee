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
#include <functional>

using namespace std;


// class Solution {
// public:
//     string getEncryptedString(string s, int k) {
//         int n = s.size();
//         string res = s;

//         for(int i = 0; i < n; i++)
//         {
//             res[i] = s[(i + k) % n];
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     string t;
//     vector<string> res;

//     void dfs(int i, int n)
//     {
//         if(i >= n)
//         {
//             int cnt = 0, st = 1;
//             for(int i = 0, j = 0; i < n; i++)
//             {
//                 if(t[i] == '1') cnt++;
//                 if(i >= 1)
//                 {
//                     if(cnt == 0) st = 0;
//                     cnt -= t[j++] - '0';
//                 }
//             }
//             if(st) res.push_back(t);
//             return;
//         }
//         t += '0';
//         dfs(i + 1, n);
//         t.pop_back();

//         t += '1';
//         dfs(i + 1, n);
//         t.pop_back();
//     }
//     vector<string> validStrings(int n) {
//         dfs(0, n);
//         return res;
//     }
// };

// class Solution {
// public:
//     int numberOfSubmatrices(vector<vector<char>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<int>> s(m + 1, vector<int>(n + 1));
//         vector<vector<int>> a(m + 1, vector<int>(n + 1));
//         for(int i = 1; i <= m; i++)
//         {
//             for(int j = 1; j <= n; j++)
//             {
//                 int x = grid[i - 1][j - 1] == 'X' ? 1 : 0;
//                 s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
//                 int y = grid[i - 1][j - 1] == 'Y' ? 1 : 0;
//                 a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + y;
//             }
//         }

//         int res = 0;
//         for(int i = 0; i < m; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(s[i + 1][j + 1] == a[i + 1][j + 1] && s[i + 1][j + 1]) res++;
//             }
//         }
//         return res;
//     }
// };
