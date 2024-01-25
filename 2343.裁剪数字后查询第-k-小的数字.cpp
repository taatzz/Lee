/*
 * @lc app=leetcode.cn id=2343 lang=cpp
 *
 * [2343] 裁剪数字后查询第 K 小的数字
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef pair<string, int> PII;

    static bool cmp(PII& a, PII& b)
    {
        if(a.first.size() != b.first.size())
            return a.first.size() < b.first.size();

        int n = a.first.size();
        for(int i = 0; i < n; i++)
        {
            if(a.first[i] != b.first[i]) return a.first[i] < b.first[i];
        }
        return a.second < b.second;
    }

    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto& e : queries)
        {
            int k = e[0], x = e[1];
            vector<PII> t;
            int idx = 0;
            for(auto& a : nums)
            {
                int n = a.size();
                t.push_back({a.substr(n - x, x), idx++});
            }
            sort(t.begin(), t.end(), cmp);
            res.push_back(t[k - 1].second);
        }

        return res;
    }
};
// @lc code=end

