/*
 * @lc app=leetcode.cn id=2008 lang=cpp
 *
 * [2008] 出租车的最大盈利
 */

// @lc code=start
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {

        // dp[i]:表示以i为终点的最大利润
        vector<long long> dp(n + 1);
        unordered_map<int, vector<pair<int, int>>> hash;

        for(auto e : rides)
        {
            hash[e[1]].push_back({e[0], e[2]});
        }

        dp[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1];
            if(hash.find(i) != hash.end())
            {
                for(auto e : hash[i])
                {
                    dp[i] = max(dp[i], dp[e.first] + i - e.first + e.second);
                }
            }
        }

        return dp[n];
    }
};
// @lc code=end

