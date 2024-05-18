/*
 * @lc app=leetcode.cn id=2521 lang=cpp
 *
 * [2521] 数组乘积中的不同质因数数目
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> h;

        auto find = [&](int x)
        {
            for(int i = 2; i <= x / i; i++)
            {
                if(x % i == 0)
                {
                    h.insert(i);
                    while(x % i == 0) x /= i;
                }
            }
            if(x > 1) h.insert(x);
        };

        for(auto&  e : nums)
        {
            find(e);
        }

        return h.size();
    }
};
// @lc code=end

