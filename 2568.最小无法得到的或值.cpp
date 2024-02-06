/*
 * @lc app=leetcode.cn id=2568 lang=cpp
 *
 * [2568] 最小无法得到的或值
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        unordered_set<int> h;
        for(int i = 0; i < n; i++) 
        {
            h.insert(nums[i]);
        }

        for(int i = 0; i < 32; i++)
        {
            if(h.count((1 << i)) == 0)
                return (1 << i);
        }
        return sum;
    }
};
// @lc code=end

