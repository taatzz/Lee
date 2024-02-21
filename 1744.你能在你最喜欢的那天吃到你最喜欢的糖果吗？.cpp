/*
 * @lc app=leetcode.cn id=1744 lang=cpp
 *
 * [1744] 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    typedef long long LL;
    static const int N = 100010;
    LL s[N];

    vector<bool> canEat(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];

        vector<bool> res;
        for(auto& e : queries)
        {
            int type = e[0], day = e[1], k = e[2];
            LL sum = (LL)(day + 1) * k;
            if(sum <= s[type] || s[type + 1] < day + 1) 
            {
                res.push_back(false);
                continue;
            }
            res.push_back(true);
        }

        return res;
    }
};
// @lc code=end

