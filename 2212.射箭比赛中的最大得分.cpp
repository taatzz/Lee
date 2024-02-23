/*
 * @lc app=leetcode.cn id=2212 lang=cpp
 *
 * [2212] 射箭比赛中的最大得分
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int st[15];
    int a = 0, sum = 0;
    vector<int> res;

    void dfs(vector<int>& nums, int x)
    {
        int n = nums.size();
        if(x >= n)
        {
            int cnt = 0;
            for(int i = 0; i < n; i++) 
                if(st[i] > nums[i])
                    cnt += i;
            if(cnt > a) 
            {
                res.resize(n);
                for(int i = 0; i < n; i++) res[i] = st[i];
                if(sum > 0) res[0] += sum;
                a = cnt;
            }

            return;
        }

        if(sum >= nums[x] + 1)
        {
            st[x] = nums[x] + 1;
            sum -= nums[x] + 1;
            dfs(nums, x + 1);
            sum += nums[x] + 1;
            st[x] = 0;
        }
        dfs(nums, x + 1);
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& nums) {
        sum = numArrows;
        dfs(nums, 0);

        return res;
    }
};
// @lc code=end

