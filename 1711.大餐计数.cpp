/*
 * @lc app=leetcode.cn id=1711 lang=cpp
 *
 * [1711] 大餐计数
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size(), mod = 1e9 + 7;
        int res = 0;
        unordered_map<int, int> h;

        for(int i = 0; i < n; i++)
        {
            int x = nums[i];
            for(int i = 0; i <= 21; i++)
            {
                if(h.find((1 << i) - x) != h.end()) res += h[(1 << i) - x];
            }
            if(res >= mod) res -= mod;
            h[x] ++;
        }

        return res;
    }
};
// @lc code=end

