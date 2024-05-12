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
//     int findPermutationDifference(string s, string t) {
//         int n = s.size();
//         int res = 0;
//         unordered_map<char, int> h;
//         for(int i  =0; i < n; i++)
//         {
//             h[s[i]] = i;
//         }
//         for(int i = 0; i < n; i++)
//         {
//             res += abs(h[t[i]] - i);
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     unordered_map<int, int> h;
//     int _k;
//     int dfs(vector<int>& nums, int x)
//     {
//         int n = nums.size();
//         // cout << x << endl;
//         if(x >= n) 
//             return 0;
//         if(h.count(x)) return h[x];

//         int sum = nums[x];
//         sum += dfs(nums, x + _k);
//         if(!h.count(x)) h[x] = sum;

//         return sum;
//     }

//     int maximumEnergy(vector<int>& nums, int k) {
//         int n = nums.size();
//         _k = k;
//         int mx = INT_MIN, idx = 0;
//         for(int i = 0; i < n; i++)
//         {
//             if(nums[i] > mx)
//             {
//                 mx = nums[i];
//                 idx = i;
//             }
//         }

//         int res = INT_MIN;
//         for(int i = n - 1; i >= 0; i--)
//         {
//             res = max(res, dfs(nums, i));
//         }

//         return res;
//     }
// };

class Solution {
public:
    int maxScore(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();
        
        long long f[m][n];
        long long res = -1e18;
        
        for(int i = 0; i < m; i++)
        {
            long long mn = 1e18;
            for(int j = 0; j < n; j++)
            {
                if(i > 0) mn = min(mn, f[i - 1][j]);
                if(j > 0) mn = min(mn, f[i][j - 1]);
                res = max(res, nums[i][j] - mn);
                f[i][j] = min(1LL * nums[i][j], mn);
            }
        }
        
        return res;
    }
};