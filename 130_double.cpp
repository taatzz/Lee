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
//     bool satisfiesConditions(vector<vector<int>>& nums) {
//         int m = nums.size(), n = nums[0].size();

//         for(int i = 0; i < m; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(i + 1 < m && nums[i + 1][j] != nums[i][j])  return 0;
//                 if(j + 1 < n && nums[i][j + 1] == nums[i][j]) return 0;
//             }
//         }

//         return 1;
//     }
// };


// class Solution {
// public:
//     int maxPointsInsideSquare(vector<vector<int>>& nums, string s) {
//         int n = nums.size();
//         map<long long, map<char, int>> h;
//         for(int i = 0; i < n; i++)
//         {
//             long long a = nums[i][0], b = nums[i][1];
//             long long c = max(abs(a), abs(b));
//             h[abs(c)][s[i]]++;
//         }

//         int res = 0, t = 0;
//         vector<int> cnt(26);
//         for(auto& [k, e] : h)
//         {
//             int sum = 0;
//             bool flag = 1;
//             for(auto& x : e)
//             {
//                 // cout << cnt[x.first - 'a'] << endl;
//                 if(cnt[x.first - 'a'] || x.second > 1) 
//                 {
//                     flag = false;
//                     cnt = vector<int> (26);
//                     t = 0;
//                     return res;
//                 }
//                 else 
//                 {
//                     cnt[x.first - 'a']++;
//                     sum += x.second;
//                 }
//             }
//             // cout << k << ' ' << flag << ' ' << sum << endl;
//             if(flag)
//             {
//                 t += sum;
//                 res = max(res, t);
//             }
//         }

//         return res;
//     }
// };

