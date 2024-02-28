/*
 * @lc app=leetcode.cn id=1024 lang=cpp
 *
 * [1024] 视频拼接
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& nums, int time) {
        vector<int> right(110);
        for(auto& e : nums)
        {
            int a = e[0], b = e[1];
            right[a] = max(right[a], min(time, b));
        }

        int res = 0, cur = 0, next = 0;
        for(int i = 0; i < time; i++)
        {
            next = max(next, right[i]);
            if(cur == i)
            {
                if(cur == next) return -1;
                res ++;
                cur = next;
            }
        }

        return res;
    }
};
// @lc code=end

