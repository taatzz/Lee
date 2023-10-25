/*
 * @lc app=leetcode.cn id=2698 lang=cpp
 *
 * [2698] 求一个整数的惩罚数
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    // 分割前面数字的和，当前的分割其实位置，目标数
    bool dfs(string s, int prev, int x, int target)
    {
        if(x >= s.size())
        {
            return prev == target;
        }

        int sum = 0, res = 0; // sum保存当前分割的数，res保存回溯结果
        for(int i = x; i < s.size(); i++)
        {
            sum = sum * 10 + s[i] - '0';
            // 当前分割数大于目标数直接break 后续之后变大不会变小
            if(prev + sum > target)
                break;
            res += dfs(s, prev + sum, i + 1, target);
        }

        return res == 0 ? false : true;
    }

    int punishmentNumber(int n) {
        int res = 0;

        for(int i = 1; i <= n; i++)
        {
            string s = to_string(i * i);
            if(dfs(s, 0, 0, i))
                res += i * i;
        }

        return res;
    }
};
// @lc code=end

