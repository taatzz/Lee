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
//     int minimumBoxes(vector<int>& apple, vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         int sum = 0;
//         for(auto e : apple) sum += e;      
//         int res = 0;
//         for(int i = nums.size() - 1; i >= 0; i--)
//         {
//             sum -= nums[i];
//             res++;
//             if(sum <= 0) break;
//         }

//         return res;
//     }
// };

// T2
// class Solution {
// public:
//     long long maximumHappinessSum(vector<int>& nums, int k) {
//         priority_queue<int> q(nums.begin(), nums.end());

//         long long res = 0, cnt = 0;
//         while(q.size() && k)
//         {
//             if(q.size() == 0) break;
//             auto t = q.top();
//             q.pop();
//             res += max((long long)0, t - cnt);
//             cnt++;
//             k--;
//         }

//         return res;
//     }
// };

// T3
// class Solution {
// public:
//     vector<string> shortestSubstrings(vector<string>& arr) {
//         unordered_map<string, int> h;
//         int n = arr.size();

//         for(auto& e : arr)
//         {
//             for(int i = 0; i < e.size(); i++)
//             {
//                 for(int j = 0; j <= i; j++)
//                 {
//                     int len = i - j + 1;
//                     h[e.substr(j, len)]++;
//                 }
//             }
//         }

//         vector<string> res(n);
//         for(int i = 0; i < arr.size(); i++)
//         {
//             vector<string> s;
//             for(int j = 0; j < arr[i].size(); j++)
//             {
//                 for(int k = 0; k <= j; k++)
//                 {
//                     int len = j - k + 1;
//                     string t = arr[i].substr(k, len);
//                     s.push_back(t);
//                     h[t]--;
//                 }
//             }
            
//             string tmp = "";
//             for(int len = 1; len <= arr[i].size(); len++)
//             {
//                 for(int j = 0; j < arr[i].size(); j++)
//                 {
//                     int l = j + 1 - len;
//                     if(l < 0) continue;
//                     string t = arr[i].substr(l, len);
//                     if(h[t] == 0)
//                     {
//                         if(tmp == "") 
//                         {
//                             tmp = t;
//                             continue;
//                         }
//                         if(t.size() > t.size()) continue;
//                         else if(tmp.size() == t.size()) tmp = min(tmp, t);
//                         else if(t.size() < tmp.size()) tmp = t;
//                     }
//                 }
//             }
//             for(auto e : s) h[e]++;
//             res[i] = tmp;
//         }

//         return res;
//     }
// };
