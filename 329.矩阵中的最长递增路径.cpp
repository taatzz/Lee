/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    static const int N = 210;
    int mem[N][N];

    int dfs(vector<vector<int>>& nums, int x, int y)
    {
        int m = nums.size(), n = nums[0].size();
        int& res = mem[x][y];
        if(res) return res;

        int cnt = 1;
        for(int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < m && b >= 0 && b < n && nums[a][b] > nums[x][y])
            {
                cnt = max(cnt, dfs(nums, a, b) + 1);
            }
        }

        return res = cnt;
    }

    int longestIncreasingPath(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();
        int res = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!mem[i][j])
                    res = max(res, dfs(nums, i, j));
            }
        }

        return res;
    }
};
// @lc code=end

