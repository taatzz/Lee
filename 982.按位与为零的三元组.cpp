/*
 * @lc app=leetcode.cn id=982 lang=cpp
 *
 * [982] 按位与为零的三元组
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> h;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                h[nums[i] & nums[j]]++;
            }
        }

        int res = 0;
        for(auto& [k, e] : h)
        {
            if(k > (1 << 16)) break;
            for(int i = 0; i < n; i++)
            {
                if((nums[i] & k) == 0) res += e;
            }
        }

        return res;
    }
};
// @lc code=end

