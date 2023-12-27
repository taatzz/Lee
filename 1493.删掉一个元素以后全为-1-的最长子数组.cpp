/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), res = 0;
        int a[2];

        for(int i = 0, j = 0; i < n; i++)
        {
            a[nums[i]]++;
            while(j <= i && a[0] > 1) a[nums[j++]]--;
            res = max(res, i - j); // 除去一个0所以不加1
        }

        return res;
    }
};
// @lc code=end

