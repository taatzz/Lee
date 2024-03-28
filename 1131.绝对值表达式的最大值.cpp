/*
 * @lc app=leetcode.cn id=1131 lang=cpp
 *
 * [1131] 绝对值表达式的最大值
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int res = 0, n = arr1.size();
        int mn = arr1[0] + arr2[0] + 0;
        for(int i = 1; i < n; i++)
        {
            res = max(res, arr1[i] + arr2[i] + i - mn);
            mn = min(mn, arr1[i] + arr2[i] + i);
        }

        mn =  0 - arr1[0] + arr2[0] + 0;
        for(int i = 1; i < n; i++)
        {
            res = max(res, arr2[i] - arr1[i] + i - mn);
            mn = min(mn, arr2[i] - arr1[i] + i);
        }

        mn = arr1[0] - arr2[0] + 0;
        for(int i = 1; i < n; i++)
        {
            res = max(res, arr1[i] - arr2[i] + i - mn);
            mn = min(mn, arr1[i] - arr2[i] + i);
        }

        mn = 0 - arr1[0] - arr2[0] + 0;
        for(int i = 1; i < n; i++)
        {
            res = max(res, i - arr1[i] - arr2[i] - mn);
            mn = min(mn,  i - arr1[i] - arr2[i]);
        }

        return res;
    }
};
// @lc code=end

