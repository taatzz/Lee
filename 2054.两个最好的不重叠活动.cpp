/*
 * @lc app=leetcode.cn id=2054 lang=cpp
 *
 * [2054] 两个最好的不重叠活动
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> t;

    int bs(int x)
    {
        int l = 0, r = t.size();
        
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(t[mid] >= x) r = mid;
            else l = mid + 1;
        }
        return r + 1;
    }


    int maxTwoEvents(vector<vector<int>>& nums) {
        for(auto& e : nums)
        {
            int a = e[0], b = e[1];
            t.push_back(a);
            t.push_back(b);
        }
        sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());

        unordered_map<int, vector<pair<int, int>>> h;

        for(auto& e : nums)
        {
            int a = e[0], b = e[1], c = e[2];
            a = bs(a), b = bs(b);
            h[b].push_back({a, c});
        }

        int res = 0;
        int n = t.size();
        vector<vector<int>> f(n + 1, vector<int>(2, 0));
        for(int i = 1; i <= n; i++)
        {
            if(h.find(i) != h.end())
            {
                f[i][0] = f[i - 1][0];
                for(auto& e : h[i])
                {
                    f[i][0] = max(f[i][0], e.second);
                    f[i][1] = max(f[i][1], f[e.first - 1][0] + e.second);
                }
            }
            else f[i][0] = f[i - 1][0];
            
            res = max({res, f[i][0], f[i][1]});
        }

        return res;
    }
};
// @lc code=end

