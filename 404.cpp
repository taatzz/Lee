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
//     int maxHeightOfTriangle(int a, int b) {
//         auto find = [](int a, int b)
//         {
//             int res = 0, cnt = 1;
//             while(1)
//             {
//                 if(cnt % 2)
//                 {
//                     if(a < cnt) return res;
//                     a -= cnt;
//                 }
//                 else
//                 {
//                     if(b < cnt) return res;
//                     b -= cnt;
//                 }

//                 res++, cnt++;
//             }
//         };

//         return max(find(a, b), find(b, a));
//     }
// };

// class Solution {
// public:
//     int maximumLength(vector<int>& nums) {
//         auto find = [&](int a, int k)->int
//         {
//             int n = nums.size();
//             if(a == 0)
//             {
//                 int res = 0;
//                 for(int i = 0; i < n; i++)
//                     if(nums[i] % 2 == k) res++;
//                 return res;
//             }
//             else
//             {
//                 int res = 0;
//                 for(int i = 0; i < n; i++)
//                 {
//                     if(nums[i] % 2 == k)
//                     {
//                         res++;
//                         k ^= 1;
//                     }
//                 }
//                 return res;
//             }
//         };

//         return max({find(0, 0), find(0, 1), find(1, 0), find(1, 1)});
//     }
// };


// class Solution {
// public:
//     int maximumLength(vector<int>& nums, int k) {
//         int n = nums.size();
//         auto find = [&](int sum, int a)
//         {
//             int res = 0;
//             for(int i = 0; i < n; i++)
//             {
//                 if(nums[i] % k == a)
//                 {
//                     res++;
//                     a = sum - a;
//                 }
//             }

//             return res;
//         };

//         int res = 0;
//         for(int i = 0; i < k; i++)
//         {
//             int a = 0;
//             if(i == 0) a = find(0, 0);
//             else a = max(find(i, i - 1), find(i, i - 2));
//             res = max(res, a);
//         }

//         return res;
//     }
// };