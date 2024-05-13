/*
 * @lc app=leetcode.cn id=2857 lang=cpp
 *
 * [2857] 统计距离为 k 的点对
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countPairs(vector<vector<int>>& nums, int k) {
        unordered_map<long long, int> h;
        int res = 0;

        for(auto& e : nums)
        {
            for(int i = 0; i <= k; i++)
            {
                auto it = h.find((e[0] ^ i) * 2000000LL + (e[1] ^ (k - i)));
                if(it != h.end())
                    res += it->second;
            }
            h[e[0] * 2000000LL + e[1]]++;
        }

        return res;
    }   
};
// @lc code=end

