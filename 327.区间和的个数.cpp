/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    long long s[N];
    vector<long long> tmp;

    int lowbit(int x)
    {
        return x & -x;
    }

    void update(vector<int>& tr, int x, int c)
    {
        for(int i = x; i < tr.size(); i += lowbit(i)) tr[i] += c;
    }

    int query(vector<int>& tr, int x)
    {
        int res = 0;
        for(int i = x; i; i -= lowbit(i)) res += tr[i];

        return res;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        for(int i = 1; i <= n; i++) 
        {
            s[i] = s[i - 1] + nums[i - 1];
            tmp.push_back(s[i]);
        }
        tmp.push_back(0);

        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        int m = tmp.size();
        vector<int> tr(m + 1);

        int res = 0;
        for(int i = 0; i <= n; i++)
        {
            long long x = s[i] - lower;
            int r = upper_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
            x = s[i] - upper;
            int l = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
            res += query(tr, r) - query(tr, l);

            update(tr, lower_bound(tmp.begin(), tmp.end(), s[i]) - tmp.begin() + 1, 1);
        }

        return res;
    }
};
// @lc code=end

