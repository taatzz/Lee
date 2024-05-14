/*
 * @lc app=leetcode.cn id=2244 lang=cpp
 *
 * [2244] 完成所有任务需要的最少轮数
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& nums) {
        unordered_map<int, int> h;
        for(auto& e : nums) h[e]++;

        int res = 0;
        for(auto& [_, e] : h)
        {
            if(e == 1) return -1;
            res += (e + 3 - 1) / 3;
        }

        return res;
    }
};
// @lc code=end

