/*
 * @lc app=leetcode.cn id=2576 lang=cpp
 *
 * [2576] 求出最多标记下标
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     // 二分答案
//     bool check(vector<int>& nums, int k)
//     {
//         int n = nums.size();
//         int res = 0;
//         for(int i = 0; i < k; i++)
//         {
//             if(nums[i] * 2 > nums[n - k + i])
//                 return false;
//         }

//         return 1;
//     }

//     int maxNumOfMarkedIndices(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         int n = nums.size();
//         int l = 0, r = n / 2 + 1;
//         while(l + 1< r)
//         {
//             int mid = l + (r - l) / 2;
//             if(check(nums, mid)) l = mid;
//             else r = mid;
//         }

//         return l * 2;
//     }
// };
// @lc code=end

// 双指针
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int i = 0, n = nums.size();
        for (int j = (n + 1) / 2; j < n; ++j)
            if (nums[i] * 2 <= nums[j])
                ++i;
        return i * 2;
    }
};