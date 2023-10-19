/*
 * @lc app=leetcode.cn id=1726 lang=c
 *
 * [1726] 同积元组
 */

// @lc code=start
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // 哈希表统计数组中所有乘积出现的次数，求当前乘积的组合数
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                cnt[nums[i] * nums[j]]++;
            }
        }
        for (auto it : cnt) {
            ans += it.second * (it.second - 1) * 4;
        }
        return ans;
    }
};
// @lc code=end

