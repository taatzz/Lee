/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    void insert(vector<int>& b, int x, int y, int c)
    {
        b[x] += c;
        b[y + 1] -= c;
    }

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> b(n + 2);

        for(auto e : bookings)
        {
            insert(b, e[0], e[1], e[2]);
        }

        vector<int> res;
        for(int i = 1; i <= n; i++)
        {
            b[i] += b[i-1];
            res.push_back(b[i]);
        }

        return b;
    }
};
// @lc code=end

