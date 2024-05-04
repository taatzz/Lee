/*
 * @lc app=leetcode.cn id=1235 lang=cpp
 *
 * [1235] 规划兼职工作
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        vector<vector<int>> t;
        for(int i = 0; i < start.size(); i++)
        {
            t.push_back({end[i], start[i], profit[i]});
        }

        sort(t.begin(), t.end());

        vector<int> f(t.size() + 1);
        for(int i = 0; i < t.size(); i++)
        {
            int j = upper_bound(t.begin(), t.begin() + i, vector<int>{t[i][1], INT_MAX}) - t.begin();
            f[i + 1] = max(f[i], f[j] + t[i][2]);
        }

        return f[t.size()];
    }
};
// @lc code=end

