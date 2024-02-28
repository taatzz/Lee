/*
 * @lc app=leetcode.cn id=2305 lang=cpp
 *
 * [2305] 公平分发饼干
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int res = INT_MAX;

    void dfs(vector<int>& nums, vector<int>& t, int x, int k)
    {
        int n = nums.size();
        if(x < 0)
        {
            int mx = 0;
            vector<int> cnt(k);
            for(int i = 0; i < t.size(); i++)
            {
                mx = max(mx, t[i]);
            }

            res = min(res, mx);
            return;
        }
        int zerocnt = 0;
        for(int e : t) 
            if(e == 0) zerocnt++;
        if(zerocnt > x + 1) return;

        for(int i : t)
            if(i > res) return;

        for(int i = 0; i < k; i++)
        {
            if(x == n - 1 && i > 0) return;

            t[i] += nums[x];
            dfs(nums, t, x - 1, k);
            t[i] -= nums[x];
        }
    }

    int distributeCookies(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> t(k);
        dfs(nums, t, nums.size() - 1, k);

        return res;
    }
};
// @lc code=end

