/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    // 循环模拟左闭右开的区间
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));

        int circlenum = n / 2, startx = 0, starty = 0; // 循环次数，开始行开始列
        int count = 1, offerset = 1; // 填进数组的数字和每行需要缩减的数量

        while(circlenum--)
        {
            int i = startx, j = starty;
            // 上行从左到右
            for(; j < n - offerset; j++)
            {
                res[startx][j] = count++;
            }
            // 右行从上到下
            for(i = startx; i < n - offerset; i++)
            {
                res[i][j] = count++;
            }
            // 下行从右到左
            for(j = i; j > starty; j--)
            {
                res[i][j] = count++;
            }
            // 左行从下到上
            for(; i > startx; i--)
            {
                res[i][j] = count++;
            }

            startx++;
            starty++;
            offerset += 1;
        }

        if(n % 2)
            res[n / 2][n / 2] = count;

        return res;
    }
};
// @lc code=end

