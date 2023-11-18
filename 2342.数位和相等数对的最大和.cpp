/*
 * @lc app=leetcode.cn id=2342 lang=cpp
 *
 * [2342] 数位和相等数对的最大和
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        // 哈希表保存每个数位和的最大值
        unordered_map<int, int> hash;
        int res = 0;
        for(auto e : nums)
        {
            int sum = 0;
            int t = e; // 保存当前的数字
            while(e)
            {
                sum += e % 10;
                e /= 10;
            }
            // 存在相同数位和更新答案
            if(hash.find(sum) != hash.end())
            {
                res = max(res, hash[sum] + t);
                // 大于当前的最大值更新最大值
                if(t > hash[sum]) hash[sum] = t;
            }
            else hash[sum] = t;
        }
        // res == 0 说明没有相同的位数和
        return res == 0 ? -1 : res;
    }
};
// @lc code=end

