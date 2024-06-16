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

// T1
// class Solution {
// public:
//     int countCompleteDayPairs(vector<int>& nums) {
//         int n = nums.size(), res = 0;

//         for(int i = 0; i < n; i++)
//         {
//             for(int j = i - 1; j >= 0; j--)
//             {
//                 if((nums[i] + nums[j]) % 24 == 0) res++;
//             }
//         }

//         return res;
//     }
// };

// T2
// class Solution {
// public:
//     long long countCompleteDayPairs(vector<int>& nums) {
//         long long n = nums.size(), res = 0;

//         map<int, int> h;
//         for(int i = 0; i < n; i++)
//         {
//             res += h[(24 - nums[i] % 24) % 24];
//             h[nums[i] % 24]++;
//         }

//         return res;
//     }
// };

// T3
// class Solution {
// public:
//     long long maximumTotalDamage(vector<int>& nums) {
//         map<long long, int> h;
//         for(int e : nums) h[e]++;
//         vector<pair<long long, int>> t;
//         for(auto e : h) t.push_back(e);

//         int n = t.size();
//         vector<long long> mem(n + 1, -1);
        
//         auto dfs = [&](auto&& dfs, int i)->long long
//         {
//             if(i < 0) return 0;
//             long long& res = mem[i];
//             if(mem[i] != -1) return mem[i];

//             auto& [x, c] = t[i];
//             int j = i;
//             while(j && t[j - 1].first >= x - 2) j--;
//             return res = max(dfs(dfs, i - 1), dfs(dfs, j - 1) + x * c);
//         };

//         return dfs(dfs, n - 1);
//     }
// };

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> tr(n + 1);
        
        auto insert = [&](int x, int c)
        {
            for(; x < tr.size(); x += x & -x)
                tr[x] += c;
        };
        auto query = [&](int x)
        {
            long long res = 0;
            for(; x; x -= x & -x)
                res += tr[x];
            return res;
        };

        vector<int> st(n);
        for(int i = 1; i < n - 1; i++)
        {
            if(nums[i] > nums[i - 1] and nums[i] > nums[i + 1]) 
                insert(i + 1, 1), st[i] = 1;
        }

        vector<int> res;
        for(auto& e : queries)
        {
            int a = e[0], l = e[1], r = e[2];
            if(a == 1)
            {
                res.push_back(max(0LL, query(r) - query(l + 1)));
            }
            else
            {
                nums[l] = r;
                for(int i = l - 1; i <= l + 1; i++)
                {
                    if(i <= 0 || i >= n - 1) continue;
                    if(st[i] && (nums[i - 1] >= nums[i] || nums[i + 1] >= nums[i]))
                    {
                        st[i] = 0;
                        insert(i + 1, -1);
                    }
                    else if(!st[i] && (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]))
                    {
                        insert(i + 1, 1);
                        st[i] = 1;
                    }
                }
            }
        }

        return res;
    }
};