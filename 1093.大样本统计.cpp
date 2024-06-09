/*
 * @lc app=leetcode.cn id=1093 lang=cpp
 *
 * [1093] 大样本统计
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& nums) {
        vector<double> res(5);

        int n = nums.size(), mx = INT_MIN, mn = INT_MAX;
        long long sum = 0, cnt = 0, t = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i])
            {
                mx = max(mx, i);
                mn = min(mn, i);
                cnt += nums[i];
                sum += 1LL * nums[i] * i;
                if(nums[i] > t) t = nums[i], res[4] = i;
            }
        }
        res[0] = mn, res[1] = mx, res[2] = sum * 1.0 / cnt;

        auto find = [&](int x)
        {
            int t = 0;
            for(int i = 0; i < n; i++)
            {
                t += nums[i];
                if(t >= x) return i;
            }
            return 0;
        };

        res[3] = cnt % 2 == 0 ? (double)(find(cnt / 2 + 1) + find(cnt / 2)) / 2.0 : (double)find(cnt / 2 + 1);

        return res;
    }
};
// @lc code=end

