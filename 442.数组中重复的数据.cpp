/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n + 1);

        for(int i = 0; i < n; i++)
        {
            cnt[nums[i]]++;
        }

        vector<int> res;
        for(int i = 0; i <= n; i++)
            if(cnt[i] == 2) res.push_back(i);
        
        return res;
    }
};
// @lc code=end

