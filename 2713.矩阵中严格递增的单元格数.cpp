/*
 * @lc app=leetcode.cn id=2713 lang=cpp
 *
 * [2713] 矩阵中严格递增的单元格数
 */

// @lc code=start
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();

        typedef pair<int, int> pii;
        map<int, vector<pii>> h;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                h[nums[i][j]].emplace_back(i, j);
            }
        }
        int res = 0;
        vector<int> row(m + 1, INT_MIN), col(n + 1, INT_MIN);
        for(auto& [k, e] : h)
        {
            vector<pii> rtmp, ctmp;
            for(int i = 0; i < e.size(); i++)
            {
                int a = e[i].first, b = e[i].second;
                int t = max(1, max(row[a], col[b]) + 1);
                res = max(res, t);
                rtmp.emplace_back(a, t);
                ctmp.emplace_back(b, t);
            }
            for(pii p : rtmp) row[p.first] = max(row[p.first], p.second);
            for(pii p : ctmp) col[p.first] = max(col[p.first], p.second);
        }

        return res;
    }
};
// @lc code=end

