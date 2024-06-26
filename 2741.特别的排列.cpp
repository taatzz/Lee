/*
 * @lc app=leetcode.cn id=2741 lang=cpp
 *
 * [2741] 特别的排列
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int n = nums.size(), sum = (1 << n) - 1;
        int mod = 1e9 + 7;
        vector<vector<long long>> mem(sum, vector<long long>(n + 1, -1));

        auto dfs = [&](auto&& dfs, int sum, int i)->long long
        {
            if(sum == 0) return 1;

            auto& res = mem[sum][i];
            if(res != -1) return res;
            res = 0;

            for(int j = 0; j < n; j++)
            {
                if((sum >> j & 1) && (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0))
                    res += dfs(dfs, 1 << j ^ sum, j);
            }

            return res;
        };

        long long res = 0;
        for(int i = 0; i < n; i++)
        {
            res += dfs(dfs, sum ^ (1 << i), i);
        }

        return res % mod;
    }
};
// @lc code=end

