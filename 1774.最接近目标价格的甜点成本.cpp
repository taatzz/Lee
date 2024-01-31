/*
 * @lc app=leetcode.cn id=1774 lang=cpp
 *
 * [1774] 最接近目标价格的甜点成本
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int res = 1e9;

    void dfs(vector<int>& nums, int x, int sum, int _t)
    {
        int n = nums.size();
        if(x == n)
        {
            if(abs(sum - _t) <= abs(res - _t))
            {
                if(abs(sum - _t) == abs(res - _t))
                    res = min(res, sum);
                else res = sum;
            }
            return;
        }

        for(int i = 0; i <= 2; i++)
        {
            dfs(nums, x + 1, sum + nums[x] * i, _t);
        }
    }

    int closestCost(vector<int>& b, vector<int>& t, int target) {
        int n = b.size(), _t = target;

        for(int i = 0; i < n; i++)
        {
            dfs(t, 0, b[i], target);
        }

        return res;
    }
};
// @lc code=end

