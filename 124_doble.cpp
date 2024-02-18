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
//     int maxOperations(vector<int>& nums) {
//         int n = nums.size();
//         int k = nums[0] + nums[1];
//         int res = 1;

//         for(int i = 2; i < n; i += 2)
//         {
//             if(i + 1 < n && nums[i] + nums[i + 1] == k) res++;
//             else break;
//         }

//         return res;
//     }
// };

// T2
// class Solution {
// public:
//     string lastNonEmptyString(string s) {
//         int n = s.size();
//         unordered_map<char, pair<int, int>> h;
//         int mx = 0;

//         for(int i = 0; i < n; i++)
//         {
//             char c = s[i];
//             if(h.find(c) == h.end())
//             {
//                 h[c] = {1, i};
//             }
//             else
//             {
//                 auto t = h[c];
//                 t.first ++;
//                 t.second = max(t.second, i);
//                 h[c] = t;
//             }
//             mx = max(mx, h[c].first);
//         }

//         vector<int> t;
//         for(auto& [_, e] : h)
//         {
//             if(e.first == mx) t.push_back(e.second);
//         }
//         sort(t.begin(), t.end());

//         string res;
//         for(auto& e : t) res += s[e];

//         return res;
//     }
// };


// T4
class Solution {
public:
    // 定义f[i] 表示以i为最后一个数字结尾的最大子序列长度
    // f[i + 1] = f[i] + 1
    // f[i] = f[i - 1] + 1
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size(), res = 0;
        sort(nums.begin(), nums.end());

        unordered_map<int, int> f;
        for(int i = 0; i < n; i++)
        {
            f[nums[i] + 1] = f[nums[i]] + 1;
            f[nums[i]] = f[nums[i] - 1] + 1;
        
        }
        for(auto e : f) res = max(res, e.second);

        return res;
    }
};