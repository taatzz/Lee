/*
 * @lc app=leetcode.cn id=2136 lang=cpp
 *
 * [2136] 全部开花的最早一天
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const bool cmp(pair<int, int>& a, pair<int, int>& b)
    {
        return a.first > b.first;
    }

    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int> > tmp;
        for(int i = 0; i < n; i++)
        {
            tmp.push_back( {growTime[i], plantTime[i]} );
        }
        sort(tmp.begin(), tmp.end(), cmp);
        int res = 0, days = 0;

        for(int i = 0; i < n; i++)
        {
            auto t = tmp[i];
            days += t.second;
            res = max(res, days + t.first);
        }

        return res;
    }
};
// @lc code=end

