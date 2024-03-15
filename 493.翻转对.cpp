/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> tmp;

    // int find(long long x)
    // {
    //     int l = 0, r = tmp.size() - 1;
    //     while(l < r)
    //     {
    //         int mid = (l + r + 1) >> 1;
    //         if(tmp[mid] <= x) l = mid;
    //         else r = mid - 1;
    //     }
    //     cout << x << " " << r << endl;
    //     if(r == tmp.size() - 1) return tmp[r] >= x ? r + 1 : tmp.size();

    //     return l + 1;
    // }

    int lowbit(int x)
    {
        return x & -x;
    }

    int query(vector<int>& tr, int x)
    {
        int res = 0;
        for(int i = x; i; i -= lowbit(i)) res += tr[i];

        return res;
    }

    void update(vector<int>& tr, int x, int c)
    {
        for(int i = x; i < tr.size(); i += lowbit(i)) tr[i] += c;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        tmp = nums;

        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        int m = tmp.size();
        vector<int> tr(m + 1);
        
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            int idx = upper_bound(tmp.begin(), tmp.end(), (long long)nums[i] * 2) - tmp.begin();
            res += query(tr, m) - query(tr, idx);
            update(tr, lower_bound(tmp.begin(), tmp.end(), nums[i]) - tmp.begin() + 1, 1);
        }

        return res;
    }
};
// @lc code=end

