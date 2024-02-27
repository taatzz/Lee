/*
 * @lc app=leetcode.cn id=1601 lang=cpp
 *
 * [1601] 最多可达成的换楼请求数目
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int res = 0, _n;
    vector<int> path;

    void dfs(vector<vector<int>>& nums, int x)
    {
        int n = nums.size();
        if(x >= n)
        {
            vector<int> st(_n);
            for(int i = 0; i < path.size(); i++)
            {
                int a = nums[path[i]][0], b = nums[path[i]][1];
                st[a]--, st[b]++;
            }
            bool flag = true;
            for(int i = 0; i < _n; i++)
                if(st[i] != 0) flag = false;
            if(flag) res = max(res, (int)path.size());
            
            return;
        }

        path.push_back(x);
        dfs(nums, x + 1);
        path.pop_back();

        dfs(nums, x + 1);
    }

    int maximumRequests(int n, vector<vector<int>>& nums) {
        _n = n;
        dfs(nums, 0);

        return res;
    }
};
// @lc code=end

