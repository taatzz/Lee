/*
 * @lc app=leetcode.cn id=1387 lang=cpp
 *
 * [1387] 将整数按权重排序
 */

// @lc code=start
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    unordered_map<int, int> h;

    int dfs(int x)
    {
        if(x == 1) return 0;

        int& res = h[x];
        if(res) return res;
        if(x % 2)
        {
            x = x * 3 + 1;
            res += dfs(x) + 1;
        }
        else res += dfs(x / 2) + 1;

        return res;
    }

    int getKth(int lo, int hi, int k) {
        int n = hi - lo + 1;
        vector<pair<int, int>> res(n);

        int idx = 0;
        for(int i = hi; i >= lo; i--)
        {
            int a = dfs(i), b = i;
            res[idx++] = {a, b};
        }

        sort(res.begin(), res.end());

        return res[k - 1].second;
    }
};
// @lc code=end

