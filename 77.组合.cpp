/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>

using namespace std;

const int N = 21;
int arr[N];

class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> res;

    /// @brief 递归求组合
    /// @param x 当前考虑的位置
    /// @param start 开始输入的数
    /// @param n 1-n的集合
    /// @param k k个位置
    void dfs(int x, int start, int n, int k)
    {
        if(x > k)
        {
            // for(int i = 0; i < k; i++)
            // {
            //     tmp[i] = arr[i + 1];
            // }
            res.push_back(tmp);
            return;
        }

        for(int i = start; i <= n -(k - tmp.size()) + 1; i++)
        {
            tmp.push_back(i);
            dfs(x + 1, i + 1, n, k);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        tmp.resize(k);
        dfs(1, 1, n, k);

        return res;
    }
};
// @lc code=end

