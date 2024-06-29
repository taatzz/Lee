/*
 * @lc app=leetcode.cn id=2763 lang=cpp
 *
 * [2763] 所有子数组中不平衡数字之和
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            vector<bool> st(n + 2, 0);
            st[nums[i]] = 1;
            for(int j = i + 1; j < n; j++)
            {
                int x = nums[j];
                if(!st[x])
                {
                    cnt += 1 - st[x - 1] - st[x + 1];
                    st[x] = 1;
                }
                res += cnt;
            }
        }

        return res;
    }
};
// @lc code=end

