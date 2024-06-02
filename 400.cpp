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

// t1
// class Solution {
// public:
//     int minimumChairs(string s) {
//         int n = s.size();

//         int res = 0, cnt = 0;
//         for(int i = 0; i < n; i++)
//         {
//             if(s[i] == 'E') 
//             {
//                 if(res == cnt) res++, cnt++;
//                 else res++;
//             }
//             else res--;
//         }

//         return cnt;
//     }
// };

// T2
// class Solution {
// public:
//     vector<int> t;
//     int countDays(int days, vector<vector<int>>& nums) {
//         int n = nums.size();
       
//         sort(nums.begin(), nums.end());

//         int st = -2e9, ed = -2e9, res = 0;
//         vector<pair<int, int>> t;
//         for(auto& e : nums)
//         {
//             int a = e[0], b = e[1];
//             if(ed < a)
//             {
//                 if(ed != -2e9) 
//                 {
//                     t.push_back({st, ed});
//                 }
//                 else res += a - 1;
//                 if(ed != -2e9) res += a - ed - 1;
//                 st = a, ed = b;
//             }
//             else ed = max(ed, b);
//         }
//         res += days - ed;

//         return res;
//     }
// };

// T3
// class Solution {
// public:
//     string clearStars(string s) {
//         int n = s.size();
//         vector<int> st(n);

//         map<char, vector<int>> h;
//         for(int i = 0; i < n; i++)
//         {
//             if(s[i] == '*')
//             {
//                 int idx = h.begin()->second.back();
//                 st[idx] = 1;
//                 st[i] = 1;
//                 h.begin()->second.pop_back();
//                 if( h.begin()->second.size() == 0) h.erase(h.begin());
//             }
//             else h[s[i]].push_back(i);
//         }

//         string res;
//         for(int i = 0; i < n; i++)
//             if(!st[i]) res += s[i];

//         return res;
//     }
// };

// T4
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        int res = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            res = min(res, abs(nums[i] - k));
            for(int j = i - 1; j >= 0; j--)
            {
                nums[j] &= nums[i];
                if(nums[j] == 0) 
                {
                    res = min(res, abs(nums[j] - k));
                    break;
                }
                if(j != i - 1 && nums[j] == nums[j + 1]) break;
                int t = abs(nums[j] - k);
                res = min(res, t);
            }
        }

        return res;
    }
};