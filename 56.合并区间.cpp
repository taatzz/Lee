/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1)
            return intervals;

        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> res; // 保存结果


        for(int i = 1; i < intervals.size(); i++)
        {   
            if(intervals[i - 1][1] < intervals[i][0]) // 前一个区间和当前的区间不重叠
                res.push_back(intervals[i - 1]);
            else // 前一个区间和这一个区间重叠
            {
                // 保存重叠后的区间和后面的区间进行比较，如果重叠继续合并，不重叠保存
                intervals[i][0] = min(intervals[i - 1][0], intervals[i][0]);
                intervals[i][1] = max(intervals[i - 1][1], intervals[i][1]);
            }
        }
        // 保存最后一个区间
        res.push_back(intervals[intervals.size() - 1]); 

        return res;
    }
};
// @lc code=end

