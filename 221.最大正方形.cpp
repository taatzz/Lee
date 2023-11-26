/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 310;
    int s[N][N];

    bool check(int m, int n, int x)
    {
        for(int i = 0; i <= m - x; i++)
        {
            for(int j = 0; j <= n - x; j++)
            {
                int x1 = i + 1, y1 = j + 1;
                int x2 = x1 + x - 1, y2 = y1 + x - 1;
                int t = s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
                if(t == x * x)
                    return true;
            }
        }

        return false;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i-1][j-1] - '0';

        int l = 0, r = min(m, n);

        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(check(m, n, mid)) l = mid;
            else r = mid - 1;
        }

        return l * l;
    }
};
// @lc code=end

