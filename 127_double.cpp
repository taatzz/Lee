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
//     int minimumSubarrayLength(vector<int>& nums, int k) {
//         int res = INT_MAX;
//         for(int i = 0; i < nums.size(); i++)
//         {
//             int cnt = 0;
//             for(int j = i; j >= 0; j--)
//             {
//                 cnt |= nums[j];
//                 if(cnt == k) res = min(res, i - j + 1);
//             }
//         }      

//         return res;
//     }
// };

// class Solution {
// public:
//     static const int N = 100010;
//     int s[N];    
    
//     int minimumLevels(vector<int>& nums) {
//         int n = nums.size();
        
//         for(int i = 1; i <= n; i++) s[i] = s[i - 1] + (nums[i - 1] == 0 ? -1 : 1);
        
//         int res = INT_MAX;
//         for(int i = 0; i < n; i++)
//         {
//             int sum = s[i + 1], next = s[n] - s[i + 1];
//             if(sum > next) res = min(res, i + 1);
//         }
//         if(res == n) return -1;
        
//         return res == INT_MAX ? -1 : res;
//     }
// };

// T3
// class Solution {
// public:
//     static const int N = 200010;
//     int s[N][32];
    
//     bool check(vector<int>& nums, int x, int k)
//     {
//         for(int i = x - 1; i < nums.size(); i++)
//         {
//             int j = i - x + 1;
//             int cnt = 0;
//             for(int k = 0; k < 32; k++)
//             {
//                 if(s[i + 1][k] - s[j][k] > 0)
//                 {
//                     cnt |= (1 << k);
//                 }
//             }
//             if(cnt >= k) return 1;
//         }

//         return 0;
//     }

//     int minimumSubarrayLength(vector<int>& nums, int k) {
//         int n = nums.size();

//         int sum = 0, l = 0, r = n;
//         for(int i = 1; i <= n; i++) 
//         {
//             sum |= nums[i - 1];
//             for(int j = 0; j < 32; j++)
//             {
//                 if((nums[i - 1] >> j & 1) == 1)
//                 {
//                     s[i][j] = s[i - 1][j] + 1;
//                 }
//                 else s[i][j] = s[i - 1][j];
//             }
//         }

//         while(l < r)
//         {
//             int mid = (l + r) >> 1;
//             if(check(nums, mid, k)) r = mid;
//             else l = mid + 1;
//         }

//         if(l == n && sum < k) return -1;
//         return l;
//     }
// };