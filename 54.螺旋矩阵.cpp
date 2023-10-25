/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int minnum = min(m, n);
        int circle = minnum / 2, startx = 0, starty = 0, ofrset = 1;
        vector<int> res;
        int i, j;

        while(circle--)
        {
            i = startx;
            j = starty;
            // 上方从左到右
            for(j = starty; j < n - ofrset; j++)
            {
                res.push_back(matrix[startx][j]);
            }
            // 右方从上到下
            for(i = startx; i < m - ofrset; i++)
            {
                res.push_back(matrix[i][j]);
            }
            // 下方从右到左
            for(; j > starty; j--)
                res.push_back(matrix[i][j]);
            // 左方从下到上
            for(; i > startx; i--)
                res.push_back(matrix[i][j]);
            startx++;
            starty++;
            ofrset++;
        }      
        if(minnum % 2 == 1)
        {
            i = startx;
            j = starty;
            if(minnum == m)
            {
                for(;j < n - ofrset + 1; j++)
                    res.push_back(matrix[startx][j]);
            }
            else
            {
                for(; i < m - ofrset + 1; i++)
                    res.push_back(matrix[i][j]);
            }
        }

        return res;
    }
};
// @lc code=end

