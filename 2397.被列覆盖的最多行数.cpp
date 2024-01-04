/*
 * @lc app=leetcode.cn id=2397 lang=cpp
 *
 * [2397] 被列覆盖的最多行数
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int res = 0, tmp = 0;
    unordered_map<int, int> h;

    // 指数型枚举选和不选
    void dfs(int x, int sum, int n, int k)
    {
        if(x == n || sum == k)
        {
            if(sum != k) return;
            int cnt = 0;
            for(auto& e : h)
            {
                if(e.first == 0 || e.first == tmp)
                    cnt += e.second;
                else
                {
                    int t = e.first;
                    bool flag = true;
                    for(int i = 0; i < n; i++)
                    {
                        // 判断当前位置是否是1如果是1但是我们没有选择就直接跳出循环
                        if((t & (1 << i)) == (1 << i) && (tmp & (1 << i)) != (1 << i))
                        {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) cnt += e.second;
                }
            }
            res = max(res, cnt);
            return;
        }

        tmp |= (1 << x);
        dfs(x + 1, sum + 1, n, k);
        tmp -= (1 << x);

        dfs(x + 1, sum, n, k);
    }

    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size(), n = matrix[0].size();

        // 先统计当前的矩阵代表的数字，哈希表存储
        for(int i = 0; i < m; i++)
        {
            int t = 0;
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 1)
                    t |= (1 << j);
            }
            h[t]++;
        }

        dfs(0, 0, n, numSelect);

        return res;
    }
};
// @lc code=end

