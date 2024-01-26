/*
 * @lc app=leetcode.cn id=1620 lang=cpp
 *
 * [1620] 网络信号最好的坐标
 */

// @lc code=start
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& nums, int r) {
        map<int, pair<int, int>> h;

        for(int i = 100; i >= 0; i--)
        {
            for(int j = 100; j >= 0; j--)
            {
                int x = 0;
                for(auto& e : nums)
                {
                    int a = e[0], b = e[1], c = e[2];
                    int d = (i - a) * (i - a) + (j - b) * (j - b);
                    if(d <= r * r)
                    {
                        x += c / (1 + sqrt(d));
                    }
                }
                if(h.find(x) == h.end())
                {
                    h[x] = {i, j};
                }
                else
                {
                    if(pair<int, int> {i, j} < h[x])
                        h[x] = {i, j};
                }
            }
        }

        vector<int> res;
        auto it = h.rbegin();
        res.push_back(it->second.first);
        res.push_back(it->second.second);

        return res;
    }
};
// @lc code=end

