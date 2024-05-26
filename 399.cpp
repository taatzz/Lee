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
//     int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         int n = nums1.size(), m = nums2.size();

//         int res = 0;
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 if(nums1[i] % (nums2[j] * k) == 0) res++;
//             }
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     string compressedString(string s) {
//         int n = s.size(), i = 0;
//         string res;

//         while(i < n)
//         {
//             int start = i;
//             i++;
//             while(i < n && s[i] == s[start] && i - start + 1 <= 9) i++;

//             res += to_string(i - start) + s[start];
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         long long res = 0;
//         unordered_map<int, int> h;
//         for(auto e : nums2) h[e * k]++;

//         auto find = [&](int x)->long long
//         {
//             unordered_set<int> t;
//             t.insert(x), t.insert(1);
//             long long res = 0;
//             for(int i = 2; i <= x / i; i++)
//             {
//                 if(x % i == 0)
//                 {
//                     t.insert(i);
//                     t.insert(x / i);
//                 }
//             }
//             for(auto e : t) res += h[e];

//             return res;
//         };


//         unordered_map<int, int> mem;
//         for(auto e : nums1)
//         {
//             if(mem.count(e)) res += mem[e];
//             else 
//             {
//                 long long x = find(e);
//                 mem[e] = x;
//                 res += x;
//             }
//         }

//         return res;
//     }
// };