/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> h;
        vector<int> f(n, 1);
        int res = 0;

        for(int i = 0; i < n; i++)
        {
            if(h.find(arr[i] - difference) != h.end())
                f[i] = f[h[arr[i] - difference]] + 1;
            h[arr[i]] = i;
            res = max(res, f[i]);
        }

        return res;
    }
};
// @lc code=end

