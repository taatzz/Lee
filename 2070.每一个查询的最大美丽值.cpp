/*
 * @lc app=leetcode.cn id=2070 lang=cpp
 *
 * [2070] 每一个查询的最大美丽值
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;

    // int binary_search(vector<PII>& nums, int x)
    // {
    //     int n = nums.size();
    //     int l = 0, r = n - 1;
    //     while(l < r)
    //     {
    //         int mid = (l + r + 1) >> 1;
    //         if(nums[mid].first <= x) l = mid;
    //         else r = mid - 1;
    //     }
    //     if(nums[l].first > x) return -1;

    //     return l;
    // }

    // 离线查询
    vector<int> maximumBeauty(vector<vector<int>>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<PII> t, q;
        for(int i = 0; i < n; i++)
        {
            int a = nums[i][0], b = nums[i][1];
            t.push_back({a, b});
        }
        for(int i = 0; i < m; i++)
            q.push_back({queries[i], i});

        // 查询也排序，对于第i个查询只需要查找大于前一个查询的价格值。
        sort(t.begin(), t.end());
        sort(q.begin(), q.end());

        unordered_map<int, int> h;
       
        vector<int> res(m);

        int mx = 0, i = 0; // 保存前面查询的最大值
        for(int j = 0; j < m; j++)
        {
            int x = q[j].first;
            for(; i < n && t[i].first <= x; i++)
            {
                if(t[i].second > mx)
                    mx = t[i].second;
            }
            res[q[j].second] = mx;
        }

        return res;
    }
};
// @lc code=end

