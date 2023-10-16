/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> hash;

        for(int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]] += 1;
        }

        for(auto it : hash)
        {
            if(it.second == 1)
                res.push_back(it.first);
        }

        return res;
    }
};
// @lc code=end

