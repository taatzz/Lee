/*
 * @lc app=leetcode.cn id=2111 lang=cpp
 *
 * [2111] 使数组 K 递增的最少操作次数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums, int x, int k)
    {
        int n = nums.size();
        vector<int> st(n);

        for(int i = 0; i < k; i++) st[i] = nums[i];

        int cnt = 0;
        for(int i = k; i < n; i++)
        {
            if(nums[i] >= st[i - k]) st[i] = nums[i];
            else 
            {
                cnt++;
                st[i] = st[i - k];
            }
        }

        return cnt <= x;
    }

    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();

        int l = 0, r = n;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(check(arr, mid, k)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
// @lc code=end

