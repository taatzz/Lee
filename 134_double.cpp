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
//     int numberOfAlternatingGroups(vector<int>& nums) {
//         int n = nums.size(), res = 0;
//         for(int i = 0; i < n; i++)      
//         {
//             int l = i - 1 < 0 ? n - 1 : i - 1;
//             int r = i + 1 >= n ? 0 : i + 1;
//             if(nums[i] != nums[l] && nums[i] != nums[r]) res++;
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     long long maximumPoints(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();

//         if(nums[0] > k) return 0;
//         else
//         {
//             int res = k / nums[0];
//             k %= nums[0];
//             long long sum  = 0;
//             for(int i = n - 1; i >= 1; i--) sum += nums[i];

//             return res + (sum + k) / nums[0];
//         }
//     }
// };

// class Solution {
// public:
//     int numberOfAlternatingGroups(vector<int>& t, int k) {
//         vector<int> nums = t;
//         for(auto e : t) nums.push_back(e);
//         int n = nums.size();

//         vector<int> st(n), s(n + 1);
//         for(int i = 1; i < n; i++)
//             if(nums[i] == nums[i - 1]) st[i - 1] = 1;
//         for(int i = 1; i <= n; i++ ) 
//         {
//             s[i] = s[i - 1] + st[i - 1];
//         } 

//         int res = 0;
//         for(int i = 0; i < t.size(); i++)
//         {
//             int r = i + k - 1;
//             if(s[r + 1] - s[i] == 0 || (s[r + 1] - s[i] == 1 && st[r] == 1)) res++;
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         long long res = 0;
//         vector<pair<int, int>> t;
        
//         for(int i = 0; i < n; i++)
//         {
//             for(auto& [k, e] : t)
//                 k &= nums[i];
//             t.push_back({nums[i], 1});
//             map<int, int> h;
//             for(auto& [k, e] : t) h[k] += e;
//             t.clear();

//             for(auto& [k, e] : h) t.push_back({k, e});
//             res += h[k];
//         }

//         return res;
//     }
// };