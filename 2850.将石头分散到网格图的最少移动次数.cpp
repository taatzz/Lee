/*
 * @lc app=leetcode.cn id=2850 lang=cpp
 *
 * [2850] 将石头分散到网格图的最少移动次数
 */

// @lc code=start
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int dx[4] = { 0,-1,0,1 };
    int dy[4] = { 1,0,-1,0 };

    int minimumMoves(vector<vector<int>>& grid) {
        int n = 3;
        vector<pair<int, int>> from, to;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                if(grid[i][j]) 
                    for(int k = 1; k < grid[i][j]; k++)
                        from.push_back({i, j});
                else to.push_back({i, j});
        }

        int res = INT_MAX;
        do
        {
            int sum = 0;
            for(int i = 0; i < from.size(); i++)
            {
                sum += abs(to[i].first - from[i].first) + abs(to[i].second - from[i].second);
            }
            res = min(res, sum);
        }while(next_permutation(from.begin(), from.end()));
       
        return res;
    }
};
// @lc code=end

