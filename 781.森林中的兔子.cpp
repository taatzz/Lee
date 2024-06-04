/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0, n = nums.size(), res = 0;
        while(i < n)
        {
            int start = i;
            i++;
            while(i < n && i - start < nums[start] + 1 && nums[i] == nums[start])
                i++;

            res += nums[start] + 1;
        }

        return res;
    }
};
// @lc code=end

