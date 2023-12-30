/*
 * @lc app=leetcode.cn id=1590 lang=cpp
 *
 * [1590] 使数组和能被 P 整除
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    typedef long long LL;
    static const int N = 100010;
    int s[N];

    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        for(int i = 1; i <= n; i++) s[i] = (s[i - 1] + nums[i - 1]) % p;
        int sum = s[n];

        unordered_map<int, int> h;
        int res = n;
        for(int i = 0; i <= n; i++)
        {
            h[s[i]] = i;
            auto it = h.find((s[i] - sum + p) % p);
            if(it != h.end()) res = min(res, i - it->second);
        }

        return res < n ? res : -1;
    }
};
// @lc code=end

