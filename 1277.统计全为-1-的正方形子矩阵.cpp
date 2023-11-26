/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 *
 * [1277] 统计全为 1 的正方形子矩阵
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 310;
    int s[N][N];

    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int max_b = min(m, n);

        int res = 0;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + matrix[i-1][j-1];
                if(matrix[i-1][j - 1] == 1) res++;
            }
        
        int i = 2;
        while(i <= max_b)
        {
            for(int j = 0; j <= m - i; j++)
            {
                for(int k = 0; k <= n - i; k++)
                {
                    int x1 = j + 1, y1 = k + 1; // 左上角
                    int x2 = x1 + i - 1, y2 = y1 + i - 1; // 右下角：左上角+边长-1
                    int t = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
                    if(t == i * i)
                        res++;
                }
            }
            i++;
        }

        return res;
    }
};
// @lc code=end

