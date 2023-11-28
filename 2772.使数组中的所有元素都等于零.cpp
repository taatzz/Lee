/*
 * @lc app=leetcode.cn id=2772 lang=cpp
 *
 * [2772] 使数组中的所有元素都等于零
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> d(n + 1);
        int sum_d = 0;
        for(int i = 0; i < n; i++)
        {
            sum_d += d[i];
            int x = nums[i];
            x += sum_d; // 计算差分值
            if(x == 0) continue; // 等于0不用操作
            if(x < 0 || i + k > n) return false; // 无法操作
            sum_d -= x; // 累积差分值
            d[i + k] += x; // k个元素之后在加上差分值
        }

        return true;
    }
};
// @lc code=end

