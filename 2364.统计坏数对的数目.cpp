/*
 * @lc app=leetcode.cn id=2364 lang=cpp
 *
 * [2364] 统计坏数对的数目
 */

// @lc code=start
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> h;
        int n = nums.size();

        long long res = 0;
        for(int i = 0; i < n; i++)
        {
            int x = nums[i] - i;
            if(h.find(x) != h.end()) res += h[x];
            h[x] ++;
        }

        return (long long)n * (n - 1) / 2 - res;
    }
};
// @lc code=end

