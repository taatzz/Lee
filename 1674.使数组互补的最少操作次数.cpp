/*
 * @lc app=leetcode.cn id=1674 lang=cpp
 *
 * [1674] 使数组互补的最少操作次数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> s(2 * k + 2, 0);

        int n = nums.size();
        for(int i = 0; i < n / 2; i++)
        {
            int a = nums[i], b = nums[n - i - 1];

            int l = 2, r = 2 * k;
            s[l] += 2, s[r + 1] -= 2;

            l = 1 + min(a, b), r = k + max(a, b);
            s[l] += -1, s[r + 1] -= -1;

            l = a + b, r = a + b;
            s[l] += -1, s[r + 1] -= -1;
        }   

        int res = n;
        for(int i = 2; i <= 2 * k; i++)
        {
            s[i] += s[i - 1];
            res = min(res, s[i]);
        }

        return res;
    }
};
// @lc code=end

