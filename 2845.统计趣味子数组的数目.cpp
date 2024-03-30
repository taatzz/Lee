/*
 * @lc app=leetcode.cn id=2845 lang=cpp
 *
 * [2845] 统计趣味子数组的数目
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int cnt[N];
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        for(int i = 1; i <= n; i++)
        {
            if(nums[i - 1] % m == k) cnt[i] = cnt[i - 1] + 1;
            else cnt[i] = cnt[i - 1];
        }

        unordered_map<int, int> h;
        long long res = 0;
        for(int i = 0; i <= n; i++)
        {
            int a = (cnt[i] - k + m) % m;
            if(h.count(a)) res += h[a];
            h[cnt[i] % m]++;
        }

        return res;
    }
};
// @lc code=end

