/*
 * @lc app=leetcode.cn id=923 lang=cpp
 *
 * [923] 三数之和的多种可能
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        int n = nums.size(), mod = 1e9 + 7;
        long long res = 0;

        for(int i = 2; i < n; i++)
        {
            vector<int> h(110);
            for(int j = 0; j < i; j++)
            {
                int x = target - nums[i] - nums[j];
                if(x >= 0 && x <= 100)
                {
                    res = (res + h[x]) % mod;
                }
                h[nums[j]]++;
            }
        }

        return res;
    }
};
// @lc code=end

