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

using namespace std;


// class Solution {
// public:
//     bool canAliceWin(vector<int>& nums) {
//         int n = nums.size();
//         int a = 0, b = 0, sum = 0;
//         for(int i = 0; i < n; i++)      
//         {
//             string s = to_string(nums[i]);
//             if(s.size() == 1) a += nums[i];
//             else if(s.size() == 2) b += nums[i];
//             sum += nums[i];
//         }

//         if(a > sum - a || b > sum - b) return 1;
//         else return 0;
//     }
// };

// class Solution {
// public:
//     int n, primes[100010], cnt = 0;
//     bool st[100010];

//     int nonSpecialCount(int l, int r) {
//         auto find = [&](int x)
//         {
//             for(int i = 2; i <= x; i ++)
//             {
//                 if(!st[i]) 
//                 {
//                     if(i * i > r) break;
//                     primes[cnt++] = i;
//                 }
//                 for(int j = 0; primes[j] <= x / i; j++)
//                 {
//                     st[primes[j] * i] = 1;
//                     if(i % primes[j] == 0) break;
//                 }
//             }
            
//             return cnt;
//         };
//         find(100010);

//         int res = 0, i = 0;
//         for(i = 0; i < cnt; i++)
//         {
//             if(primes[i] * primes[i] >= l) break;
//         }

//         return r - l + 1 - (cnt - i);
//     }
// };

