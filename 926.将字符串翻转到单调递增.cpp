/*
 * @lc app=leetcode.cn id=926 lang=cpp
 *
 * [926] 将字符串翻转到单调递增
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> f(n + 1, vector<int>(2));
        // f[i][0] - f[i][1] 表示当前以0或者1结尾的修改次数
        // f[i][0] 当前位置为0时的修改次数，f[i][1] 表示当前位置为1的修改次数
        for(int i = 1; i <= n; i++)
        {
            int cur = s[i - 1] - '0';
            // 当前位置为0前面必须是0，当前位置是1就翻转
            f[i][0] = f[i - 1][0] + (cur == 0 ? 0 : 1);
            // 当前位置是1前面可以是0可以是1，当前是0就翻转
            f[i][1] = min(f[i - 1][0], f[i - 1][1]) + (cur == 1 ? 0 : 1);
        }

        return min(f[n][0], f[n][1]);
    }
};
// @lc code=end

