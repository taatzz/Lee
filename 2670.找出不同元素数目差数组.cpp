/*
 * @lc app=leetcode.cn id=2670 lang=cpp
 *
 * [2670] 找出不同元素数目差数组
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> left, right; 
        for(auto& e : nums) right[e]++;

        vector<int> res(n);
        for(int i = 0; i < n; i++)
        {
            int x = nums[i];
            right[x]--, left[x] ++;
            if(right[x] == 0) right.erase(x);
            res[i] = left.size() - right.size();
        }

        return res;
    }
};
// @lc code=end

