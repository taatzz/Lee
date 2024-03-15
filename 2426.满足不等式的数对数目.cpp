/*
 * @lc app=leetcode.cn id=2426 lang=cpp
 *
 * [2426] 满足不等式的数对数目
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
            int mid = (l + r + 1) >> 1;
            if(tmp[mid] <= x) l = mid;
            else r = mid - 1;
        }
        if(l == 0) return tmp[l] <= x ? l + 1 : -1;

        return l + 1;
    }

    int lowbit(int x)
    {
        return x & -x;
    }

    long long query(vector<int>& tr, int x)
    {
        long long res = 0;
        for(int i = x; i; i -= lowbit(i)) res += tr[i];

        return res;
    }

    void update(vector<int>& tr, int x, int c)
    {
        for(int i = x; i < tr.size(); i += lowbit(i)) tr[i] += c;
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        for(int i = 0; i < min(nums1.size(), nums2.size()); i++)
        {
            tmp.push_back(nums1[i] - nums2[i]);
        }

        sort(tmp.begin(), tmp.end());
        
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        int m = tmp.size();
        vector<int> tr(m + 1);

        long long res = 0;
        for(int i = 0; i < min(nums1.size(), nums2.size()); i++)
        {
            int sum = diff + (nums1[i] - nums2[i]);
            int idx = find(sum);
            if(idx != -1)
                res += query(tr, idx);
            update(tr, find(nums1[i] - nums2[i]), 1);
        }

        return res;
    }
};
// @lc code=end

