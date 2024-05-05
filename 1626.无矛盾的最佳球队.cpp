/*
 * @lc app=leetcode.cn id=1626 lang=cpp
 *
 * [1626] 无矛盾的最佳球队
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef pair<int, int> pii;

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pii> t;
        for(int i = 0; i < ages.size(); i++)
        {
            t.emplace_back(ages[i], scores[i]);
        }

        int n = ages.size();
        sort(t.begin(), t.end(),[&](const pii& a, const pii& b)
        { 
            return a.first < b.first || (a.first == b.first && a.second < b.second);
        });

        vector<int> f(n + 1);
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            f[i] = t[i].second;
            for(int j = 0; j < i; j++)
                if(t[j].second <= t[i].second)
                    f[i] = max(f[i], f[j] + t[i].second);
            res = max(f[i], res);
        }

        return res;
    }
};
// @lc code=end

