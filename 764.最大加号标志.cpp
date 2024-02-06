/*
 * @lc app=leetcode.cn id=764 lang=cpp
 *
 * [764] 最大加号标志
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& g) {
        // 全部为0直接返回0
        if(g.size() == n * n) return 0;
        int m = n;
        vector<vector<int>> nums(m, vector<int>(n, 1));
        for(auto& e : g) nums[e[0]][e[1]] = 0;

        vector<vector<int>> right(m, vector<int>(n + 1, 0));
        vector<vector<int>> left(m, vector<int>(n + 1, 0));
        vector<vector<int>> top(m + 1, vector<int>(n, 0));
        vector<vector<int>> bottom(m + 1, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(nums[i][j - 1] == 1) left[i][j] = left[i][j - 1] + 1;
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = n - 1; j >= 0; j--)
                if(nums[i][j] == 1) right[i][j] = right[i][j + 1] + 1;
        }

        for(int j = 0; j < n; j++)
        {
            for(int i = 1; i <= m; i++)
                if(nums[i - 1][j] == 1) top[i][j] = top[i - 1][j] + 1;
        }
        for(int j = 0; j < n; j++)
        {
            for(int i = m - 1; i >= 0; i--)
                if(nums[i][j] == 1) bottom[i][j] = bottom[i + 1][j] + 1;
        }

        int res = 1;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(nums[i][j] != 1) continue;
                int t = INT_MAX;
                t = min({ left[i][j], right[i][j + 1], top[i][j], bottom[i + 1][j]});
                if(t != 0) res = max(res, t + 1);
            }
        }

        return res;
    }
};
// @lc code=end

