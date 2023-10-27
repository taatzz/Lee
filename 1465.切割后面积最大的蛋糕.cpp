/*
 * @lc app=leetcode.cn id=1465 lang=cpp
 *
 * [1465] 切割后面积最大的蛋糕
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int find_hw(vector<int>& a, int x)
    {
        int pre = 0, res = 0;
        for(auto e : a)
        {
            res = max(res, e - pre);
            pre = e;
        }
        res = max(res, x - pre);

        return res;
    }

    // 贪心，找出两条宽和高的最大值
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        int mod = 1e9 + 7;
        sort(hor.begin(), hor.end());
        sort(ver.begin(), ver.end());

        return (long long)find_hw(hor, h) * find_hw(ver, w) % mod;
    }
};
// @lc code=end

