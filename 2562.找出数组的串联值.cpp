/*
 * @lc app=leetcode.cn id=2562 lang=cpp
 *
 * [2562] 找出数组的串联值
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        int i = 0, j = nums.size() - 1;

        long long res = 0; // 防止int溢出
        while(i <= j)
        {
            string tmp;
            if(i == j)
                tmp = to_string(nums[i]);
            else
                tmp = to_string(nums[i]) + to_string(nums[j]);

            res += stoi(tmp);
            i++;
            j--;
        }

        return res;
    }
};
// @lc code=end

