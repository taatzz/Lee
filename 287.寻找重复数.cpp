/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> hash;

        for(auto e : nums)
        {
            hash[e]++;
        }

        for(auto it : hash)
        {
            if(it.second > 1)
                return it.first;
        }

        return 0;
    }
};
// @lc code=end

