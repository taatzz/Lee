/*
 * @lc app=leetcode.cn id=1521 lang=cpp
 *
 * [1521] 找到最接近目标值的函数值
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> pre;
        int res = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            vector<int> cur = {arr[i]};
            res = min(res, abs(arr[i] - target));
            for(int j = 0; j < pre.size(); j++)
            {
                cur.push_back(arr[i] & pre[j]);
                res = min(res, abs((pre[j] & arr[i]) - target));
            }

            cur.erase(unique(cur.begin(), cur.end()), cur.end());
            pre = cur;
        }

        return res;
    }
};
// @lc code=end

