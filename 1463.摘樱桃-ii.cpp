/*
 * @lc app=leetcode.cn id=1463 lang=cpp
 *
 * [1463] 摘樱桃 II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 75;
    // 第i行中第一个机器人在j和第二个机器人在k可以获得的最大数量。
    int mem[N][N][N];
    int n, m;

    int dfs(int r, int r1, int r2, vector<vector<int>>& nums)
    {
        if(mem[r][r1][r2] != -1) return mem[r][r1][r2];
        int& res = mem[r][r1][r2];

        int cur = (r1 == r2 ? nums[r][r1] : nums[r][r1] + nums[r][r2]);

        if(r == n - 1) return cur;

        int next = 0;
        for(int i = -1; i <= 1; i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                if(r1 + i >= 0 && r1 + i < m && r2 + j >= 0 && r2 + j < m)
                {
                    next = max(next, dfs(r + 1, r1 + i, r2 + j, nums));
                }
            }
        } 

        res = cur + next;
        return res;
    }

    int cherryPickup(vector<vector<int>>& nums) {
        n = nums.size(), m = nums[0].size();
        memset(mem, -1, sizeof mem);

        return dfs(0, 0, m - 1, nums);
    }
};
// @lc code=end

