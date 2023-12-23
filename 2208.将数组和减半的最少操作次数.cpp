/*
 * @lc app=leetcode.cn id=2208 lang=cpp
 *
 * [2208] 将数组和减半的最少操作次数
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        priority_queue<double> q(nums.begin(), nums.end());

        double x = sum / 2;
        int res = 0;
        while(x > 0)
        {
            double tmp = q.top();
            q.pop();
            x -= tmp / 2;
            q.push(tmp / 2);
            res++;
        }

        return res;
    }
};
// @lc code=end

