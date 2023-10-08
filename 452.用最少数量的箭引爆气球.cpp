/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);// 按照从小到大的顺序排列

        // 只要数组不为空则射箭的最小总数就是1
        int res = 1,  x = points[0][1]; //x表示当前的射箭位置
        for(int i = 1; i < points.size(); i++)
        {
            if(x < points[i][0]) // 气球不重叠最大的射箭位置无法满足箭的总数加1
            {
                res++;
                x = points[i][1]; // 更新新的射击位置
            }
            else
            {
                x = min(points[i][1], x); // x更新为最大的射击位置
            }
        }
        return res;
    }
};
// @lc code=end

