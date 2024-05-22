/*
 * @lc app=leetcode.cn id=2242 lang=cpp
 *
 * [2242] 节点序列的最大得分
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef pair<int, int> pii;
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<pii>> g(n);
        for(auto& e : edges)
        {
            int a = e[0], b = e[1];
            g[a].push_back({-scores[b], b});
            g[b].push_back({-scores[a], a});
        }

        for(auto& e : g)
        {
            if(e.size() > 3)
            {
                nth_element(e.begin(), e.begin() + 3, e.end());
                e.resize(3);
            }
        }

        int res = -1;
        for(auto& e : edges)
        {
            int a = e[0], b = e[1];
            for(auto& [s_a, x] : g[a])
            {
                for(auto& [s_b, y] : g[b])
                {
                    if(x != b && y != a && x != y)
                        res = max(res, -s_a - s_b + scores[a] + scores[b]);
                }
            }
        }

        return res;
    }
};
// @lc code=end

