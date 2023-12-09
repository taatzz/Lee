#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = s.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        vector<int> dp(n + 1);

        unordered_map<char, int> hash;
        for(int i = 0; i < chars.size(); i++) hash[chars[i]] = vals[i];

        // for(int i = 1; i <= n; i++)
        // {
        //     int w;
        //     if(hash.find(s[i - 1]) == hash.end()) w = s[i - 1] - 'a' + 1;
        //     else w = hash[s[i - 1]];
        //     dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        //     dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + w;
        // }

        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            int w;
            if(hash.find(s[i - 1]) == hash.end()) w = s[i - 1] - 'a' + 1;
            else w = hash[s[i - 1]];
            // dp[i]: 表示当前以i结尾的子串的最大开销
            // 选当前字符时: dp[i] = dp[i - 1] + w;
            // 不选因为是连续子串所以就是w
            dp[i] = max(w, dp[i - 1] + w);
            res = max(res, dp[i]);
        }

        return res;
    }
};