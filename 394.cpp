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
//     int numberOfSpecialChars(string s) {
//         unordered_set<char> h;
//         for(auto& e : s)
//         {
//             h.insert(e);
//         }

//         int res = 0;
//         for(int i = 0; i < s.size(); i++)
//         {
//             int x = s[i] - 'a';
//             if(x >= 'a' && x < 'z')
//             {
//                 char c = toupper(s[i]);
//                 if(h.count(c)) res++;
//             }
//         }

//         return res;
//     }
// };


// class Solution {
// public:
//     int numberOfSpecialChars(string s) {
//         unordered_set<char> res;
//         set<int> h[26];
//         for(int i = 0; i < s.size(); i++)
//         {
//             if(s[i] >= 'a' && s[i] <= 'z')
//                 h[s[i] - 'a'].insert(i);
//         }
        
//         vector<int> st(26, 0);
//         for(int i = 0; i < s.size(); i++)
//         {
//             if(s[i] >= 'A' && s[i] <= 'Z')
//             {
//                 char c = tolower(s[i]);
//                 if(h[c - 'a'].size() == 0) continue;
//                 if(h[c - 'a'].lower_bound(i) == h[c - 'a'].end() && !st[s[i] - 'A'])  
//                 {
//                     res.insert(c);
//                     // cout << c << endl;
//                 }
//                 else
//                 {
//                     st[s[i] - 'A'] = 1;
//                 }
//             }
//         }

//         return res.size();
//     }
// };

// class Solution {
// public:
//     int minimumOperations(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<int>> cnt, f;
//         f.resize(n + 1, vector<int>(10, INT_MAX));
//         cnt.resize(n + 1, vector<int>(10, 0));

//         for(int j = n - 1; j >= 0; j--)
//         {
//             for(int i = 0; i < m; i++)
//                 cnt[j][grid[i][j]]++;
//         }

//         for(int i = 0; i < 10; i++)
//         {
//             f[n - 1][i] = m - cnt[n - 1][i];
//         }

//         for(int j = n - 2; j >= 0; j--)
//         {
//             for(int i = 0; i < 10; i++)
//             {
//                 for(int k = 0; k < 10; k++)
//                 {
//                     if(k == i) continue;
//                     f[j][i] = min(f[j][i], f[j + 1][k] + m - cnt[j][i]);
//                 }
//             }
//         }

//         int res = INT_MAX;
//         for(int i = 0; i < 10; i++) res = min(res, f[0][i]);

//         return res;
//     }
// };