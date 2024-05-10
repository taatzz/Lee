/*
 * @lc app=leetcode.cn id=1943 lang=cpp
 *
 * [1943] 描述绘画结果
 */

// @lc code=start
#include <vector>
#include <map>

using namespace std;


#define ll long long
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, ll> mp;
        for (const auto& v: segments) {
            int start = v[0], end = v[1], color = v[2];
            mp[start] += color;
            mp[end] -= color;
        }

        vector<vector<ll>> ans;
        ll last = 0, col = 0;
        for (const auto& p: mp) {
            if (col != 0) ans.push_back({last, p.first, col});
            last = p.first;
            col += p.second;
        }
        
        return ans;
    }
};
// @lc code=end

