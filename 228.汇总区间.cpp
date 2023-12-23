/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        int i = 0;

        while(i < n)
        {
            int start = i;
            i ++;
            while(i < n && (long long)nums[i] - nums[i - 1] == 1) i++;
            int t = i - start;
            if(t == 1)
            {
                string tmp = to_string(nums[start]);
                res.push_back(tmp);
            }
            else
            {
                string tmp = to_string(nums[start]) + "->" + to_string(nums[i - 1]);
                res.push_back(tmp);
            }
        }

        return res;
    }
};
// @lc code=end

