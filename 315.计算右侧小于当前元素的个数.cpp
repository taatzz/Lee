/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> tmp;

    int find(int x)
    {
        int l = 0, r = tmp.size() - 1;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(tmp[mid] >= x) r = mid;
            else l = mid + 1;
        }

        return r + 1;
    }

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

    vector<int> countSmaller(vector<int>& nums) {
        tmp = nums;

        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        int m = tmp.size();
        vector<int> tr(m + 1);

        vector<int> res;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            int idx = find(nums[i]);
            int sum = query(tr, idx - 1);
            res.push_back(sum);
            update(tr, idx, 1);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end

