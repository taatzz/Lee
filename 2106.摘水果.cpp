/*
 * @lc app=leetcode.cn id=2106 lang=cpp
 *
 * [2106] 摘水果
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int maxTotalFruits(vector<vector<int>>& a, int startPos, int k) {
        int n = a.size();
        vector<int> t, s;
        s.push_back(0);
        for(int i = 1; i <= n; i++)
        {
            t.push_back(a[i - 1][0]);
            s.push_back(a[i - 1][1] + s[i - 1]);
        }

        int res = 0;
        for(int x = k; x >= 0; x--)
        {
            int y = (k - x) / 2;
            int l = startPos - x, r = startPos + y;
            auto pl = lower_bound(t.begin(), t.end(), l) - t.begin();
            auto pr = upper_bound(t.begin(), t.end(), r) - t.begin();
            res = max(res, s[pr] - s[pl]);

            l = startPos - y, r = startPos + x;
            pl = lower_bound(t.begin(), t.end(), l) - t.begin();
            pr = upper_bound(t.begin(), t.end(), r) - t.begin();
            res = max(res, s[pr] - s[pl]);
        }

        return res;
    }
};
// @lc code=end

