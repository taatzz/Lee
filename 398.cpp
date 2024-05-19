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
#include <array>

using namespace std;

// class Solution {
// public:
//     bool isArraySpecial(vector<int>& nums) {
//         int n = nums.size();

//         for(int i = 1; i < n; i++)
//         {
//             if(nums[i - 1] % 2 == nums[i] % 2) return 0;
//         }

//         return 1;
//     }
// };


// class Solution {
// public:
//     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
//         int n = nums.size();
//         set<int> h;
//         for(int i = 1; i < n; i++)
//         {
//             if(nums[i] % 2 == nums[i - 1] % 2) h.insert(i - 1);
//         }

//         vector<bool> res;
//         for(auto& e : queries)
//         {
//             int l = e[0], r = e[1];
//             if(r - l + 1 < 2) 
//             {
//                 res.push_back(1);
//                 continue;
//             }
//             auto a = h.lower_bound(l);
//             if(a == h.end()) res.push_back(1);
//             else
//             {
//                 if(*a < r) res.push_back(0);
//                 else res.push_back(1);
//             }
            
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     long long sumDigitDifferences(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<long long>> h(32, vector<long long>(10));

//         auto find = [&](int x)
//         {
//             int idx = 0;
//             while(x)
//             {
//                 h[idx][x % 10]++;
//                 x /= 10;
//                 idx++;
//             }
//         };

//         for(int i = 0; i < n; i++)
//         {
//             find(nums[i]);
//         }

//         long long res = 0;
//         for(int i = 0; i < 32; i++) 
//         {
//             for(int j = 0; j < 10; j++)
//             {
//                 if(h[i][j] == 0) continue;
//                 for(int k = j + 1; k < 10; k++)
//                 {
//                     if(h[i][k] != 0)
//                     {
//                         res += h[i][j] * h[i][k];
//                     }
//                 }
//             }
//         }

//         return res;
//     }
// };

class Solution {
public:
    int _k;
    map<array<int,3>, int> mem;
    int dfs(int x, bool st, int jump)
    {
        if(x > _k + 1 || x + (1 << jump) < 0) return 0;
        array<int, 3> t = {x, st, jump};
        if(mem.find(t) != mem.end()) return mem[t];

        int res = x == _k ? 1 : 0;
        if(st != 0 && x != 0)
            res += dfs(x - 1, 0, jump);
        res += dfs(x + (1 << jump), 1, jump + 1);

        return mem[t] = res;
    }

    int waysToReachStair(int k) {
        _k = k;
        return dfs(1, 1, 0);
    }
};