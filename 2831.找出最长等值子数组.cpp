/*
 * @lc app=leetcode.cn id=2831 lang=cpp
 *
 * [2831] 找出最长等值子数组
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> h;
        for(int i = 0; i < n; i++) h[nums[i]].push_back(i);

        int res = 0;
        for(auto& e : h)
        {
            auto& vec = e.second;
            for(int i = 0, j = 0; i < vec.size(); i++)
            {
                while(j <= i && (vec[i] - vec[j] + 1) - (i - j + 1) > k) j++;
                res = max(res, i - j + 1);
            }
        }

        return res;
    }
};
// @lc code=end

