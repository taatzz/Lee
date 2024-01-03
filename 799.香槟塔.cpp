/*
 * @lc app=leetcode.cn id=799 lang=cpp
 *
 * [799] 香槟塔
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int x, int y) {
        vector<vector<double>> f(110, vector<double>(110, 0));

        f[1][1] = poured;
        for(int i = 2; i <= x + 1; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                double left = f[i - 1][j - 1] - 1, right = f[i - 1][j] - 1;
                if(left >= 0)
                    f[i][j] += left / 2.0;
                if(right >= 0)
                    f[i][j] += right / 2.0;
            }
        }
        
        return f[x + 1][y + 1] > 1.0 ? 1.0 : f[x + 1][y + 1];
    }
};
// @lc code=end

