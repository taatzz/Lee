/*
 * @lc app=leetcode.cn id=1847 lang=cpp
 *
 * [1847] 最近的房间
 */

// @lc code=start
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end(), 
        [&](const vector<int>& a, vector<int>& b){return a[1] > b[1];});
        for(int i = 0; i < queries.size(); i++)
        {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), 
        [&](const vector<int>& a, vector<int>& b){return a[1] > b[1];});

        set<int> h;
        vector<int> res(queries.size());
        for(int i = 0, j = 0; i < queries.size(); i++)
        {
            while(j < nums.size() && queries[i][1] <= nums[j][1])
            {
                h.insert(nums[j][0]);
                j++;
            }
            if(h.size() == 0)
            {
                res[queries[i][2]] = -1;
            }
            else
            {
                int x= queries[i][0], idx = queries[i][2];
                auto it = h.lower_bound(x);
                int dist = INT_MAX;
                if(it != h.end() && *it - x < dist)
                {
                    dist = *it - x;
                    res[idx] = *it;
                }
                if(it != h.begin())
                {
                    it = prev(it);
                    if(x - *it <= dist)
                    {
                        res[idx] = *it;
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end

