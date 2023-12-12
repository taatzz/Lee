/*
 * @lc app=leetcode.cn id=2841 lang=cpp
 *
 * [2841] 几乎唯一子数组的最大和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    typedef long long LL;

    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        unordered_map<int, int> h;

        int cnt = 0;
        LL res = 0, sum = 0;
        for(int i = 0; i < k - 1; i ++) 
        {
            h[nums[i]]++;
            sum += nums[i];
        }
        
        for(int i = k - 1; i < n; i++)
        {
            h[nums[i]]++;
            sum += nums[i];
            if(h.size() >= m) res = max(res, sum);

            int j = i - k + 1;
            h[nums[j]] --;
            if(h[nums[j]] == 0) h.erase(nums[j]);
            sum -= nums[j];
        }

        return res;
    }
};
// @lc code=end

