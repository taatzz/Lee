/*
 * @lc app=leetcode.cn id=2420 lang=cpp
 *
 * [2420] 找到所有好下标
 */

// @lc code=start
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1); 
        // 统计每个位置的最长序列
        for(int i = 1; i < n; i ++)
            if(nums[i] <= nums[i - 1])
                left[i] = left[i - 1] + 1;
        for(int i = n - 2; i >= 0; i --)
            if(nums[i] <= nums[i + 1])
                right[i] = right[i + 1] + 1;
        
        vector<int> res;
        // left[i - 1] && right[i + 1] >= k
        for(int i = k; i < n - k; i++)
        {
            if(left[i - 1] >= k && right[i + 1] >= k)
                res.push_back(i);
        }

        return res;
    }
};
// @lc code=end

