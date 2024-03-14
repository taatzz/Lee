/*
 * @lc app=leetcode.cn id=2564 lang=cpp
 *
 * [2564] 子字符串异或查询
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;

    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        unordered_map<int, PII> h;

        for(int i = 0; i < n; i++)
        {
            int x = 0;
            for(int j = i; j < min(i + 30, n); j++)
            {
                x = (x << 1) | (s[j] - '0');
                if(h.find(x) == h.end()) h[x] = {i, j};
                else
                {
                    int x1 = j - i + 1;
                    int x2 = h[x].second - h[x].first + 1;
                    if(x1 < x2) h[x] = {i, j};
                }
            }
        }

        vector<vector<int>> res;
        for(auto& e : queries)
        {
            int x = e[0] ^ e[1];
            if(h.find(x) != h.end()) res.push_back({h[x].first, h[x].second});
            else res.push_back({-1, -1});
        }

        return res;
    }
};
// @lc code=end

