/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <vector>

using namespace std;

// class Solution {
// public:
//     int res = 0;

//     void dfs(vector<int>& n, int sum, int x, int target)
//     {
//         if(x >= n.size() || sum == target)
//         {   
//             if(sum == target)
//                 res++;
//             return;
//         }

//         dfs(n, sum + n[x], x + 1, target);
//         dfs(n, sum - n[x], x + 1, target);
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int> st(n, 0);
        
//         dfs(nums, 0, 0, target);

//         return res;
//     }
// };
// @lc code=end

// TLE
// 指数型枚举
// class Solution {
// public:
//     int res = 0;

//     void dfs(vector<int>& n, vector<int>& s, int x, int target)
//     {
//         if(x == n.size())
//         {
//             int sum = 0;
//             for(int i = 0; i < s.size(); i++)
//             {
//                 if(s[i] == 1)
//                     sum += n[i];
//                 else
//                     sum -= n[i];
//             }
//             if(sum == target)
//                 res++;
//             return;
//         }
//         s[x] = 1;
//         dfs(n, s, x + 1, target);
//         s[x] = 0;

//         s[x] = 2;
//         dfs(n ,s, x + 1, target);
//         s[x] = 0;
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int> st(n ,0);

//         dfs(nums, st, 0, target);

//         return res;
//     }
// };

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        int diff = sum - target;
        if(diff < 0 || diff % 2)
            return 0;

        int neg = diff / 2;
        vector<vector<int> > dp(nums.size(), vector<int>(neg + 1, 0));
        dp[0][0] = 1;

        for(int i = 1; i <= nums.size(); i++)
        {
            int num = nums[i-1];
            for(int j = 0; j <= neg; j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j >= num)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-num];
            }
        }

        return dp[nums.size()][neg];
    }
};

