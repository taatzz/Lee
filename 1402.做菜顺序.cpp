/*
 * @lc app=leetcode.cn id=1402 lang=cpp
 *
 * [1402] 做菜顺序
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     int maxSatisfaction(vector<int>& satisfaction) {
//         sort(satisfaction.begin(), satisfaction.end(), greater<int>());

//         int res = 0, prev = 0;
//         for(int i = 0; i < satisfaction.size(); i++)
//         {
//             if(satisfaction[i] + prev > 0)
//             {
//                 prev += satisfaction[i];
//                 res += prev;
//             }
//             else break;
//         }

//         return res;
//     }
// };
// @lc code=end


class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction)
    {
        int n = satisfaction.size();

        int res = 0;
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                dp[i][j] = dp[i-1][j-1] + j * satisfaction[j - 1];
                if(j < i)
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                
                res = max(dp[i][j], res);
            }
        }

        return res;
    }
};