/*
 * @lc app=leetcode.cn id=862 lang=cpp
 *
 * [862] 和至少为 K 的最短子数组
 */

// @lc code=start
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    long long s[N];

    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];

        deque<int> dq;
        int res = n + 1;
        for(int i = 0; i <= n; i++)
        {
            long long cur = s[i];
            while(!dq.empty() && cur - s[dq.front()] >= k)
            {
                res = min(res, i - dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && s[dq.back()] >= cur)
                dq.pop_back();
            dq.push_back(i);
        }

        return res > n ? -1 : res;
    }
};
// @lc code=end

