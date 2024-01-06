/*
 * @lc app=leetcode.cn id=2536 lang=cpp
 *
 * [2536] 子矩阵元素加 1
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 510;
    int s[N][N];

    void insert(int x1, int y1, int x2, int y2)
    {
        s[x1][y1] += 1;
        s[x1][y2 + 1] -= 1;
        s[x2 + 1][y1] -= 1;
        s[x2 + 1][y2 + 1] += 1;
    }

    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n, vector<int>(n, 0));

        for(auto e : queries)
        {
            int x1 = e[0], y1= e[1], x2 = e[2], y2 = e[3];
            insert(x1 + 1, y1 + 1, x2 + 1, y2 + 1);
        }

        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= n; j++)
            {
                s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
                res[i - 1][j - 1] = s[i][j];
            }
        }

        return res;
    }
};
// @lc code=end

