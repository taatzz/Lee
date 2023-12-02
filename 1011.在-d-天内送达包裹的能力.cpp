/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& w, int x, int days)
    {
        int sum = 0, res = 1;
        for(auto e : w)
        {
            if(sum + e > x)
            {
                res++;
                sum = 0;
            }
            sum += e;
        }

        return res <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0, m = 0;
        for(auto e : weights) 
        {
            sum += e;
            m = max(m, e);
        }
        int l = m, r = sum;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(check(weights, mid, days)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
// @lc code=end

