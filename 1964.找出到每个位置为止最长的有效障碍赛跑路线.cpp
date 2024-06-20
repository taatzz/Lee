/*
 * @lc app=leetcode.cn id=1964 lang=cpp
 *
 * [1964] 找出到每个位置为止最长的有效障碍赛跑路线
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        vector<int> t = nums;
        sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());

        int n = t.size();
        vector<int> tr(n + 1, 0);
        auto insert = [&](int x, int c)
        {
            for(; x < tr.size(); x += x & -x) 
                tr[x] = max(tr[x], c);
        };
        auto query = [&](int x)
        {
            int res = 0;
            for(; x; x -= x & -x)
                res = max(res, tr[x]);

            return res;
        };

        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            int idx = lower_bound(t.begin(), t.end(), nums[i]) - t.begin() + 1;
            int mx = query(idx);
            res.push_back(mx + 1);
            insert(idx, mx + 1);
        }

        return res;
    }
};
// @lc code=end

