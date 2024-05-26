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
//     int duplicateNumbersXOR(vector<int>& nums) {
//         unordered_map<int, int> h;
//         for(auto& e : nums) h[e]++;

//         int res = 0;
//         for(auto [k, e] : h)
//             if(e == 2) res ^= k;

//         return res;
//     }
// };

// class Solution {
// public:
//     vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
//         int n = nums.size();
//         unordered_map<int, set<int>> h;
//         vector<int> t;
//         for(int i = 0; i < n; i++)
//         {
//             h[nums[i]].insert(i);
//             if(nums[i] == x) t.push_back(i);
//         }

//         vector<int> res;
//         for(auto& e : queries)
//         {
//             if(e - 1 >= t.size()) res.push_back(-1);
//             else res.push_back(t[e - 1]);
//         }

//         return res;
//     }
// };


// class Solution {
// public:
//     vector<int> queryResults(int k, vector<vector<int>>& queries) {
//         int n = queries.size();
//         vector<int> res;
        
//         unordered_map<int, int> h, num;
//         for(auto& e : queries)
//         {
//             int a = e[0], b = e[1];
//             if(h.count(a))
//             {
//                 int c = h[a];
//                 num[c]--;
//                 if(num[c] == 0) num.erase(c);
//                 h[a] = b;
//                 num[b]++;
//             }
//             else
//             {
//                 h[a] = b, num[b]++;
//             }
//             res.push_back(num.size());
//         }

//         return res;
//     }
// };


