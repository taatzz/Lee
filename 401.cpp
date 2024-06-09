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


// class Solution {
// public:
//     int numberOfChild(int n, int k) {
//         int cnt = 1;
//         while(k >= n - 1) k -= n - 1, cnt++;
//         int res = 0;
//         if(cnt % 2) return k;
//         else return n - k - 1;
//     }
// };

// class Solution {
// public:
//     int valueAfterKSeconds(int n, int k) {
//         vector<long long> s(n + 1, 1);
//         int mod = 1e9 + 7;
//         s[0] = 0;

//         for(int i = 1; i <= k; i++)
//         {
//             long long pre = 0;
//             for(int j = 1; j <= n; j++)
//             {
//                 long long t = s[j];
//                 s[j] = (s[j] + pre) % mod;
//                 pre = (pre + t) % mod;
//             }
//         }

//         return s[n] % mod;
//     }
// };

class Solution {
public:
    int maxTotalReward(vector<int>& nums) {
        int n = nums.size();
        vector<bool> st(n);
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        unordered_map<int, int> h;
        function<int(int)> dfs = [&](int x)
        {   
            int res = 0;
            if(h.count(x)) return h[x];
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] > x)
                {
                    res = max(res, dfs(x + nums[i]) + nums[i]);
                }
            }
            
            return h[x] = res;
        };

        return dfs(0);
    }
};
