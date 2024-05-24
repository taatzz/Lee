/*
 * @lc app=leetcode.cn id=2501 lang=cpp
 *
 * [2501] 数组中最长的方波
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <functional>

using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set st(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> mem(1e5 + 10);
        function<int(int)> dfs = [&](int x)->int
        {   
            int sq = sqrt(x);
            if(sq * sq != x || !st.count(sq)) return 1;

            if(mem[x]) return mem[x];
            int res = dfs(sq) + 1;
            mem[x] = res;

            return res;
        };

        int res = 0;
        for(auto& e : nums) res = max(res, dfs(e));

        return res > 1 ? res : -1;
    }
};
// @lc code=end

