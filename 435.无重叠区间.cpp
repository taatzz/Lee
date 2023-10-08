/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 一定是去排序右边界
        // 右边界一定可以找到一个最优的情况
        // |              |
        //   |     |
        //           |  |
        //                |  |  这样就多删了一个
        sort(intervals.begin(), intervals.end(), cmp);

        int res = 0, x = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(x > intervals[i][0]) // 前一个区间大于当前区间的起点，删除
            {
                res++;
            }
            else
            {
                x = intervals[i][1]; // 区间不重叠，更新区间右边界
            }
        }
        return res;
    }
};
// @lc code=end

