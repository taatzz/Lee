/*
 * @lc app=leetcode.cn id=2848 lang=cpp
 *
 * [2848] 与车相交的点
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> s(110, 0);

        for(auto& e : nums)
        {
            int l = e[0], r = e[1];
            s[l] += 1, s[r + 1] -= 1;
        }
        for(int i = 1; i <= 100; i++) s[i] += s[i - 1];

        int res = 0;
        for(int i = 1; i <= 100; i++)
            if(s[i]) res++;

        return res;
    }
};
// @lc code=end

