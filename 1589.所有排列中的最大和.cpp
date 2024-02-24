/*
 * @lc app=leetcode.cn id=1589 lang=cpp
 *
 * [1589] 所有排列中的最大和
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    bool st[N];
    long long s[N];
    int b[N];

    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size(), mod = 1e9 + 7;
        // 差分
        for(auto& e : requests)
        {
            b[e[0]] += 1;
            b[e[1] + 1] -= 1;
        }
        for(int i = 0; i <= n; i++) b[i + 1] += b[i];

        // 根据出现次数进行分配并更新对答案的贡献
        sort(b, b + n);
        sort(nums.begin(), nums.end());
        long long res = 0;
        for(int i = n - 1; i >= 0 && b[i] > 0; i--) res += (long long) nums[i] * b[i];
    
        return res % mod;
    }
};
// @lc code=end

