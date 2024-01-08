/*
 * @lc app=leetcode.cn id=2398 lang=cpp
 *
 * [2398] 预算内的最多机器人数目
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 50010;
    long long s[N];

    bool check(vector<int>& nums, long long x, long long k)
    {
        int q[N * 2], hh = 0, tt = -1;

        for(int i = 0; i < nums.size(); i++)
        {
            if(hh <= tt && i - q[hh] + 1 > x) hh++;

            while(hh <= tt && nums[q[tt]] <= nums[i]) tt--;

            q[++tt] = i;

            if(i >= x - 1)
            {
                int r = i, l = i - x + 1;
                long long sum = s[r + 1] - s[l];
                if(nums[q[hh]] + x * sum <= k) return true;
            }
        }

        return false;
    }

    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        for(int i = 1; i <= runningCosts.size(); i++)
            s[i] = s[i - 1] + runningCosts[i - 1];

        int n = chargeTimes.size();
        long long l = 0, r = n;

        while(l < r)
        {
            long long mid = (l + r + 1) >> 1;
            if(check(chargeTimes, mid, budget)) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
// @lc code=end

