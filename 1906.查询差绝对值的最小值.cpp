/*
 * @lc app=leetcode.cn id=1906 lang=cpp
 *
 * [1906] 查询差绝对值的最小值
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> cnt(n + 1, vector<int>(110));

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= 100; j++)
            {
                cnt[i][j] = cnt[i - 1][j];
            }
            cnt[i][nums[i - 1]]++;
        }

        vector<int> res;
        for(auto& e : queries)
        {
            int l = e[0], r = e[1];
            int pre = -1, t = INT_MAX;
            for(int i = 1; i <= 100; i++)
            {
                int x = cnt[r + 1][i] - cnt[l][i];
                if(x != 0 && pre == -1) pre = i;
                else if(x != 0 && pre != -1) 
                {
                    t = min(t, abs(pre - i));
                    pre = i;
                }
            }
            if(t == INT_MAX) t = -1;
            res.push_back(t);
        }

        return res;
    }
};
// @lc code=end

