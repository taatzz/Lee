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
//     bool check(vector<int>& a, vector<int>& b, int x)
//     {
//         unordered_map<int, int> h1, h2;
//         for(auto& e : a) h1[e + x]++;
//         for(auto& e : b) h2[e]++;

//         for(auto& [k, e] : h1)
//         {
//             // cout << k << " " << x << endl;
//             if(!h2.count(k)) return false;
//             if(e != h2[k]) return false;
//         }
//         // cout << endl;

//         return true;
//     }

//     int addedInteger(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         for(int i = 0; i <= 1000; i++)
//         {
//             if(check(nums1, nums2, i)) return i; 
//             if(check(nums1, nums2, -i)) return -i;  
//         }

//         return -1;
//     }
// };

// class Solution {
// public:
//     unordered_map<int, int> h2;
//     bool check(vector<int>& a, vector<int>& b, int x)
//     {
//         unordered_map<int, int> h1;
//         for(auto& e : a) h1[e + x]++;

//         int cnt = 2;
//         for(auto& [k, e] : h1)
//         {
//             // cout << k << " " << e << ' ' << x << endl;
//             if(!h2.count(k))
//             {
//                 if(e > cnt || cnt == 0) return false;
//                 else cnt -= e;
//             }
//             else if(e != h2[k])
//             {
//                 if(cnt < abs(e - h2[k]) || cnt == 0)
//                 {
//                     return false;
//                 }
//                 else cnt -= abs(e - h2[k]);
//             }
//         }

//         return true;
//     }
//     int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
//         for(auto& e : nums2) h2[e]++;
//         int n = nums1.size();
//         int res = INT_MAX;
//         for(int i = -1000; i <= 0; i++)
//         {
//             if(check(nums1, nums2, i)) return i;
//         }
        
//         for(int i = 0; i <= 1000; i++)
//         {
//             if(check(nums1, nums2, i)) return i;
//         }

//         return res;
//     }
// };
