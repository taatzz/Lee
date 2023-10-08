/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:

    int dfs(long long n)
    {
        if(n == 1)
            return 0;
        if(n == 2)
            return 1;
        if(n % 2 == 0)
            return dfs(n / 2) + 1;
        else
            return min(dfs(n + 1), dfs(n - 1)) + 1;
    }

    int integerReplacement(int n) {
        return dfs(n);
    }
};
// @lc code=end

