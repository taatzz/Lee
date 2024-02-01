/*
 * @lc app=leetcode.cn id=2672 lang=cpp
 *
 * [2672] 有相同颜色的相邻元素数目
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> color(n);
        int m = queries.size();
        vector<int> ans(m);
        color[queries[0][0]] = queries[0][1];

        for(int i = 1; i < m; i++)
        {
            int a = queries[i][0], b = queries[i][1];
            int x = ans[i - 1];
            if(a - 1 >= 0)
            {
                // 前面已经相等然后更改之后不相等答案减一
                if(color[a] == color[a - 1] && color[a] != 0)
                {
                    if(b != color[a - 1]) x--;
                }
                // 前面不相等更改之后相等答案加一
                else if(color[a] != color[a - 1])
                {
                    if(b == color[a - 1]) x++;
                }
            }
            if(a + 1 < n)
            {
                if(color[a] == color[a + 1] && color[a] != 0)
                {
                    if(b != color[a + 1]) x--;
                }
                else if(color[a] != color[a + 1])
                {
                    if(b == color[a + 1]) x++;
                }
            }
            color[a] = b;
            ans[i] = x;
        }

        return ans;
    }
};
// @lc code=end

