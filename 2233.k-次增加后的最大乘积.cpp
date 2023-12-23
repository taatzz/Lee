/*
 * @lc app=leetcode.cn id=2233 lang=cpp
 *
 * [2233] K 次增加后的最大乘积
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q(nums.begin(), nums.end());

        while(k --)
        {
            int t = q.top();
            q.pop();
            q.push(++t);
        }
        int mod = 1e9 + 7;
        long long res = 1;
        while(q.size())
        {
            res *= q.top();
            res %= mod;
            q.pop();
        }

        return res;
    }
};
// @lc code=end

