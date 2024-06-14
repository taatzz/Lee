/*
 * @lc app=leetcode.cn id=2786 lang=cpp
 *
 * [2786] 访问数组中的位置使分数最大
 */

// @lc code=start
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<long long>> mem;
    long long dfs(vector<int>& nums, int i, int j, int x)
    {
        int n = nums.size();
        if(i >= n) return 0;

        long long& res = mem[i][j];
        if(res != -1) return res;
        if(nums[i] % 2 != j)
            return res = dfs(nums, i + 1, j, x);
        return res = max(dfs(nums, i + 1, j, x), dfs(nums, i + 1, j ^ 1, x) - x) + nums[i];
    }

    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();

        mem.resize(n + 1, vector<long long>(2, -1));

        return dfs(nums, 0, nums[0] % 2, x);
    }
};
// @lc code=end

