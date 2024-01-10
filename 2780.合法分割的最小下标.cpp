/*
 * @lc app=leetcode.cn id=2780 lang=cpp
 *
 * [2780] 合法分割的最小下标
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 对于原数组求出“可支配元素”，然后从左向右枚举分割点
    // 分割点前面的可支配元素我们可以边枚举边记录，后面的用总数减去前面的
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int k = n / 2, num;
        unordered_map<int, int> h;

        for(auto e : nums)
        {
            h[e]++;
            if(h[e] >= k) num = e;
        }

        int res = -1, cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == num) cnt++;
            if(cnt * 2 > i + 1 && (h[num] - cnt) * 2 > n - i - 1)
            {
                res = i;
                break;
            }
        }

        return res;
    }
};
// @lc code=end

