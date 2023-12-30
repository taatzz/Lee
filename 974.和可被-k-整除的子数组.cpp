/*
 * @lc app=leetcode.cn id=974 lang=cpp
 *
 * [974] 和可被 K 整除的子数组
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static const int N = 30010;
    int s[N];

    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        unordered_map<int, int> h;
        h.insert({0, 1});

        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            int t = (s[i] % k + k) % k;
            res += h[t];
            h[t]++;
        }

        return res;
    }
};
// @lc code=end

