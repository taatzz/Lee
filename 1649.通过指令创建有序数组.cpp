/*
 * @lc app=leetcode.cn id=1649 lang=cpp
 *
 * [1649] 通过指令创建有序数组
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lowbit(int x)
    {
        return x & -x;
    }

    void insert(vector<int>& tr, int x, int c)
    {
        for(int i = x; i < tr.size(); i += lowbit(i))
            tr[i] += c;
    }

    long long query(vector<int>& tr, int x)
    {
        long long res = 0;
        for(int i = x; i; i -= lowbit(i))
        {
            res += tr[i];
        }

        return res;
    }

    int createSortedArray(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> tr(mx + 10, 0);
        int mod = 1e9 + 7;

        for(int i = 0; i < n; i++)
        {
            res += min(query(tr, nums[i] - 1), query(tr, mx + 1) - query(tr, nums[i]));
            
            insert(tr, nums[i], 1);
            res %= mod;
        }

        return res % mod;
    }
};
// @lc code=end

