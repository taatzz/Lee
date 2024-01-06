/*
 * @lc app=leetcode.cn id=1764 lang=cpp
 *
 * [1764] 通过连接另一个数组的子数组得到一个数组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& t, vector<int>& nums, int i)
    {
        int j;
        for(j = 0; i < nums.size() && j < t.size(); i++, j++)
            if(nums[i] != t[j]) return false;
        return j == t.size();
    }

    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0, j = 0; i < n && j < groups.size();)
        {
            if(check(groups[j], nums, i))
            {
                i += groups[j++].size();
                cnt++;
            }
            else i++;
        }

        return cnt == groups.size();
    }
};
// @lc code=end

