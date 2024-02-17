/*
 * @lc app=leetcode.cn id=2370 lang=cpp
 *
 * [2370] 最长理想子序列
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size(), res = 0;
        vector<int> f(n);
        unordered_map<int, int> h;

        for(int i = 0; i < n; i++)
        {
            int u = s[i] - 'a';
            f[i] = 1;
            for(int j = max(0, u - k); j <= min(u + k, 25); j++)
            {
                if(h.find(j) != h.end())
                    f[i] = max(f[i], h[j] + 1);
            }
            h[u] = f[i];
            res = max(res, f[i]);
        }

        return res;
    }
};
// @lc code=end

