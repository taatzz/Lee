/*
 * @lc app=leetcode.cn id=2528 lang=cpp
 *
 * [2528] 最大化城市的最小供电站数目
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    long s[N];

    long long maxPower(vector<int>& nums, int r, int k) {
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            int a = max(0, i - r), b = min(n - 1, i + r);
            s[a + 1] += nums[i];
            s[b + 2] -= nums[i];
        }
        for(int i = 1; i <= n; i++) s[i] += s[i - 1];
        long mx = *max_element(s + 1, s + n);

        auto check = [&](long x) -> bool
        {
            vector<int> t(n + 1, 0);
            long pre = 0, cnt = 0;

            for(int i = 1; i <= n; i++)
            {
                pre += t[i];
                long m = x - s[i] - pre;
                if(m > 0)
                {
                    cnt += m;
                    if(cnt > k) return false;
                    pre += m;
                    if(i + r * 2 + 1 < t.size()) t[i + r * 2 + 1] -= m;
                }
            }

            return true;
        };

        long l = 0, x = mx + k;

        while(l < x)
        {
            long mid = (l + x + 1) >> 1;
            if(check(mid)) l = mid;
            else x = mid - 1;
        }

        return l;
    }
};
// @lc code=end

