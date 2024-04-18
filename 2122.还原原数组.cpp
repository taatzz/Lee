/*
 * @lc app=leetcode.cn id=2122 lang=cpp
 *
 * [2122] 还原原数组
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> res;

    bool check(vector<int>& nums, int k)
    {
        if(k == 0) return false;
        int n = nums.size();
        vector<int> st(n, 0);
        int j = 0; // 二分起始位置
        // 每次寻找的数都是单调不降的，那么需要从上一次二分找到的位置进行查找，防止重复元素

        for(int i = 0; i < n; i++)
        {
            if(st[i]) continue;
            auto it = lower_bound(nums.begin() + j, nums.end(), nums[i] + k * 2);
            if(it == nums.end() || *it != nums[i] + k * 2) return false;
            int idx = it - nums.begin();

            st[idx] = st[i] = 1;
            j = idx + 1;
            res.push_back(nums[i] + k);
        }

        return true;
    }

    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> h;
        int n = nums.size();
        for(int j = 0; j < n; j++)
        {
            int x = abs(nums[0] - nums[j]);
            if(x % 2 == 0) h.insert(x / 2);
        }

        for(auto e : h)
        {
            if(check(nums, e)) return res;
            res.clear();
        }

        return res;
    }
};
// @lc code=end

