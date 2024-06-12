/*
 * @lc app=leetcode.cn id=2597 lang=cpp
 *
 * [2597] 美丽子集的数目
 */

// @lc code=start
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        vector<int> cnt(3010);
        function<void(int)> dfs = [&](int i)
        {
            if(i >= n)
            {
                res++;
                return;
            }
            
            int x = nums[i];
            dfs(i + 1);
            if(cnt[x + k] == 0 && (x - k < 0 || cnt[x - k] == 0))
            {
                cnt[x]++;
                dfs(i + 1);
                cnt[x]--;
            }
        };
        dfs(0);

        return res - 1;
    }
};
// @lc code=end

