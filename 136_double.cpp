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

// class Solution {
// public:
//     int winningPlayerCount(int n, vector<vector<int>>& nums) {
//         vector<vector<int>> cnt(n, vector<int>(11));
//         for(auto& e : nums)
//         {
//             cnt[e[0]][e[1]] += 1;
//         }

//         int res = 0;
//         for(int i = 0; i < n; i++)
//         {
//             bool st = 1;
//             for(int j = 0; j < 10; j++)
//             {
//                 if(cnt[i][j] && cnt[i][j] > i) res++;
//             }
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     int minFlips(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();

//         int res = INT_MAX, cnt = 0;
//         for(int i = 0; i < m; i++)
//         {
//             int l = 0, r = n - 1;
//             while(l < r) 
//             {
//                 if(grid[i][l] != grid[l][r]) cnt++;
//                 l++, r--;
//             }
//             res += cnt;
//         }
            // cnt = 0;
//         for(int j = 0; j < n; j++)
//         {
//             int l = 0, r = m - 1;
//             while(l < r) 
//             {
//                 if(grid[l][j] != grid[r][j]) cnt++;
//                 l++, r--;
//             }
//             res = min(res, cnt);
//         }

//         return res;
//     }
// };

