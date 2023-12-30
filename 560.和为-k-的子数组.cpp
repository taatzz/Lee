/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static const int N = 20010;
    int s[N];

    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];

        unordered_map<int, int> h;
        h.insert({0, 1});
        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            int t = s[i] - k;
            if(h.find(t) != h.end()) res += h[t];
            h[s[i]]++;
        }

        return res;
    }
};
// @lc code=end

