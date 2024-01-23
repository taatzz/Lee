/*
 * @lc app=leetcode.cn id=2541 lang=cpp
 *
 * [2541] 使数组中所有元素相等的最小操作数 II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k == 0)
        {
            return nums1 == nums2 ? 0 : -1;
        }

        int n = nums1.size();
        long long add = 0, sub = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums1[i] > nums2[i])
            {
                int d = nums1[i] - nums2[i];
                if(d % k != 0) return -1;
                else sub += d;
            }
            else if(nums1[i] < nums2[i])
            {
                int d = nums2[i] - nums1[i];
                if(d % k != 0) return -1;
                else add += d;
            }
        }
        if(add != sub) return -1;

        return add / k;
    }
};
// @lc code=end

