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
//     vector<int> resultArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> t1, t2;
//         t1.push_back(nums[0]);
//         t2.push_back(nums[1]);

//         for(int i = 2; i < n; i++)
//         {
//             if(t1.back() > t2.back()) t1.push_back(nums[i]);
//             else t2.push_back(nums[i]);
//         }

//         vector<int> res;
//         for(auto& e : t1) res.push_back(e);
//         for(auto& e : t2) res.push_back(e);

//         return res;
//     }
// };

// T2
// class Solution {
// public:

//     int countSubmatrices(vector<vector<int>>& grid, int k) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<long long>> s(m + 1, vector<long long>(n + 1));

//         for(int i = 1; i <= m; i++)
//         {
//             for(int j = 1; j <= n; j++)
//                 s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + nums[i - 1][j - 1];
//         }

//         int res = 0;
//         for(int i = 0; i < m; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 long long x = s[i + 1][j + 1];
//                 if(x <= k) res++;
//             }
//         }

//         return res;
//     }
// };

// T3
// class Solution {
// public:
//     int in[3], out[3];

//     int minimumOperationsToWriteY(vector<vector<int>>& grid) {
//         int n = grid.size();

//         int k = n / 2;
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(i - j == 0 && i < k && j < k) in[grid[i][j]]++;
//                 else if(i + j == n && i < k && j > k) in[grid[i][j]]++;
//                 else if(i >= k && j == k) in[grid[i][j]]++;
//                 else out[grid[i][j]]++;
//             }
//         }

//         int res = 1e9, sum1 = 0, sum2 = 0;
//         for(int i = 0; i < 3; i++) sum1 += in[i];
//         for(int i = 0; i < 3; i++) sum2 += out[i];


//         for(int i = 0; i < 3; i++)
//         {
//             int cnt1 = sum1 - in[i];
//             for(int j = 0; j < 3; j++)
//             {
//                 if(j == i) continue;
//                 int cnt2 = sum2 - out[j];

//                 res = min(res, cnt1 + cnt2);
//             }
//         }

//         return res;
//     }
// };




