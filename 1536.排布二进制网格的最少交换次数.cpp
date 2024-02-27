/*
 * @lc app=leetcode.cn id=1536 lang=cpp
 *
 * [1536] 排布二进制网格的最少交换次数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(n, 210);

        for(int i = 0; i < m; i++)
        {
            int cnt = 0;
            for(int j = n - 1; j >= 0; j--)
            {
                if(grid[i][j] == 0) cnt++;
                else break;
            }
            row[i] = min(row[i], cnt);
        }

        int res = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(row[i] >= n - i - 1) ;
            else
            {
                int j = i + 1;
                for(;j < n; j++)
                {
                    if(row[j] >= n - i - 1) break;
                }
                if(j == n) return -1;
                for(; j > i; j--)
                {
                    swap(row[j], row[j - 1]);
                    res++;
                }
            }
        }

        return res;
    }
};
// @lc code=end

