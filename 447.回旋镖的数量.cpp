/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<long long, int> h;
        int n = points.size();
        

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            h.clear();
            for(int j = 0; j < n; j++)
            {
                long long x = (long long)(points[i][0] - points[j][0]) * (points[i][0] - points[j][0]);
                long long y = (long long)(points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                res += h[x + y]++ * 2;
            }
        }

        return res;
    }
};
// @lc code=end

