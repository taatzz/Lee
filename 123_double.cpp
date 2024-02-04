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
//     string triangleType(vector<int>& nums) {
//         int a = nums[0], b = nums[1], c = nums[2];
//         if(a + b > c || a + c > b || b + c > a)
//         {
//             if(a == b == c)
//             {
//                 return "equilateral";
//             }
//             else if(a == b || a == c)
//             {
//                 return "isosceles";
//             }
//             else return "scalene";
//         }
//         else return "none";
//     }
// };


// T2、4
// class Solution {
// public:
//     static bool cmp(vector<int>& a, vector<int>& b)
//     {
//         if(a[0] != b[0]) return a[0] < b[0];
//         else return a[1] > b[1];
//     }

//     int numberOfPairs(vector<vector<int>>& nums) {
//         sort(nums.begin(), nums.end(), cmp);

//         int res = 0, n = nums.size();

//         for(int i = 0; i < n; i++)
//         {
//             int mx = INT_MIN;
//             for(int j = i + 1; j < n; j++)
//             {
//                 if(nums[j][1] > mx && nums[j][1] <= nums[i][1])
//                 {
//                     mx = nums[j][1];
//                     res++;
//                 }
//             }
//         }

//         return res;
//     }
// };

// T3
// class Solution {
// public:
//     static const int N = 100010;
//     static const long long INF = 1e16;
//     typedef long long LL;
//     LL s[N];

//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         unordered_map<int, LL> h;
//         for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];

//         LL res = -INF;
//         for(int i = 0; i < n; i++)
//         {
//             auto it = h.find(nums[i]);
//             if(it == h.end()) h[nums[i]] = s[i];
//             else if(s[i] < it->second) it->second = s[i];
            
            
//             it = h.find(nums[i] + k);
//             if(it != h.end())
//                 res = max(res, s[i + 1] - it->second);
//             it = h.find(nums[i] - k);
//             if(it != h.end())
//                 res = max(res, s[i + 1] - it->second);
//         }
        
//         return res == -INF ? 0 : res;
//     }
// };