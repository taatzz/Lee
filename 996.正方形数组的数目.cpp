/*
 * @lc app=leetcode.cn id=996 lang=cpp
 *
 * [996] 正方形数组的数目
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 15;
    unordered_set<int> h;
    int res = 0;
    bool st[N];
    vector<int> path;

    void dfs(vector<int>& nums, int x)
    {
        int n = nums.size();
        if(x >= n)
        {
            bool flag = true;
            if(flag) res++;

            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1] && !st[i - 1]) continue;
            if(!st[i])
            {
                if(path.size() == 0 || h.find(path[path.size() - 1] + nums[i]) != h.end())
                {
                    st[i] = true;
                    path.push_back(nums[i]);
                    dfs(nums, x + 1);
                    path.pop_back();
                    st[i] = false;
                }
            }
        }
    }

    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = 2e9 + 10;
        h.insert(0);
        for(int i = 1; i <= m / i; i++)
        {
            h.insert(i * i);
        }
        dfs(nums, 0);

        return res;
    }
};
// @lc code=end

