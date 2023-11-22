/*
 * @lc app=leetcode.cn id=2602 lang=cpp
 *
 * [2602] 使数组元素全部相等的最少操作次数
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    long long s[N];

    int find(vector<int>& nums, int x)
    {
        int n = nums.size();
        int l = 0, r = n;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(nums[mid] >= x) r = mid;
            else l = mid + 1;
        }

        return r;
    }

    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < nums.size(); i++)
        {
            s[i + 1] = (s[i] + nums[i]) * 1ll;
        }

        vector<long long> res;
        for(auto e : queries)
        {
            long long t = 0;
            // 找到第一个大于e的位置
            int x = find(nums, e);

            // 需要增加的区间
            t += (long long)e * x - s[x];

            // 需要减少的区间
            t += s[n] - s[x] - (long long)e * (n - x);

            res.push_back(t);
        }

        return res;
    }
};
// @lc code=end

