/*
 * @lc app=leetcode.cn id=2121 lang=cpp
 *
 * [2121] 相同元素的间隔之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    typedef long long LL;

    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, pair<vector<int>, vector<LL>> > h;
        int n = arr.size();

        for(int i = 0; i < n; i++)
        {
            h[arr[i]].first.push_back(i);
        }

        for(auto& e : h)
        {
            int m = e.second.first.size();
            e.second.second.resize(m + 1);
            for(int i = 1; i <= m; i++) 
                e.second.second[i] = e.second.second[i - 1] + e.second.first[i - 1];
        }
        vector<long long> res(n);
        for(int i = 0; i < n; i++)
        {
            int x = arr[i];
            // auto e = h[x].first;
            // auto s = h[x].second;
            int it = lower_bound(h[x].first.begin(), h[x].first.end(), i) - h[x].first.begin();
            LL left = (long long)(it + 1) * h[x].first[it] - h[x].second[it + 1];
            LL right = (h[x].second[h[x].second.size() - 1] - h[x].second[it]) - (long long)(h[x].first.size() - it) * h[x].first[it];
            res[i] = left + right;
        }

        return res;
    }
};
// @lc code=end

