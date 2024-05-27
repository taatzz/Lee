/*
 * @lc app=leetcode.cn id=2659 lang=cpp
 *
 * [2659] 将数组清空
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef pair<int, int> pii;
    long long countOperationsToEmptyArray(vector<int>& nums) {
        vector<pii> t;
        for(int i = 0; i < nums.size(); i++)
        {
            t.emplace_back(nums[i], i + 1);
        }
        sort(t.begin(), t.end());

        int m = t.size(), n = nums.size();
        vector<int> tr(m + 1);

        auto insert = [&](int x, int c)
        {
            for(int i = x; i < tr.size(); i += i & -i)
                tr[i] += c;
        };
        auto query = [&](int x)
        {
            int res = 0;
            for(int i = x; i; i -= i & -i)
                res += tr[i];
            
            return res;
        };

        long long res = 0, pre = 0;
        for(int i = 0; i < n; i++)
        {
            if(t[i].second < pre)
            {
                res += n - pre;
                res -= query(n) - query(pre);
                pre = 0;
            }
            res += t[i].second - pre;
            res -= query(t[i].second) - query(pre);
            pre = t[i].second;
            insert(t[i].second, 1);
        }

        return res;
    }
};
// @lc code=end

