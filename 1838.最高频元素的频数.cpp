/*
 * @lc app=leetcode.cn id=1838 lang=cpp
 *
 * [1838] 最高频元素的频数
 */

// @lc code=start
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    long long s[N];
    bool check(vector<int>& nums, int x, int k)
    {
        int i = 0, j = x - 1;

        for(; j < nums.size(); j++, i++)
        {
            long long t = s[j + 1] - s[i];
            // 找到一个可以通过加k个1而达到的窗口直接返回true
            if((long long)nums[j] * x - t <= k) return true;
        }
        
        return false;
    }

    int maxFrequency(vector<int>& nums, int k) {
        // 因为只能通过+1改变数组的元素所以排序看是否可以通过k次变换变成最后面的元素
        // 因为要通过变换，所以排序不会影响答案
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // 因为要计算窗口的元素和所以使用前缀和
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];

        int l = 1, r = n;
        // 二分枚举滑动窗口的大小
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(check(nums, mid, k)) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
// @lc code=end

