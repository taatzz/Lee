/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& nums, vector<int>& costs) {
        int n = nums.size();
        unordered_set h;
        for(auto e : nums) h.insert(e);

        // f[i] 表示当前第i天的最低票价
        // i 不是必须旅游的天就直接不买票
        // i必须买票时可以买1，7，30
        vector<int> f(500, 0);

        for(int i = 1; i <= 366; i++)
        {
            if(h.find(i) != h.end())
            {
                if(i - 1 >= 0)
                    f[i] = f[i - 1] + costs[0];
                if(i - 7 >= 0)
                    f[i] = min(f[i - 7] + costs[1], f[i]);
                else f[i] = min(f[0] + costs[1], f[i]);
                if(i - 30 >= 0)
                    f[i] = min(f[i - 30] + costs[2], f[i]);
                else f[i] = min(f[0] + costs[2], f[i]);
                // f[i] = min({f[max(0, i - 1)] + costs[0],
                //             f[max(0, i - 7)] + costs[1],
                //             f[max(0, i - 30)] + costs[2]});
            }
            else f[i] = f[i - 1];
        }

        return f[nums[n - 1]];
    }
};
// @lc code=end

