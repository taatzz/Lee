/*
 * @lc app=leetcode.cn id=2488 lang=cpp
 *
 * [2488] 统计中位数为 K 的子数组
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int s[N];

    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int idx = find(nums.begin(), nums.end(), k) - nums.begin();
        unordered_map<int, int> h{{0, 1}};
        for(int i = idx - 1, x = 0; i >= 0; i--)
        {
            x += nums[i] < k ? 1 : -1;
            h[x]++;
        }

        int res = h[0] + h[-1];
        for(int i = idx + 1, x = 0; i < n; i++)
        {
            x += nums[i] > k ? 1 : -1;
            res += h[x] + h[x - 1];
        }

        return res;
    }
};
// @lc code=end

