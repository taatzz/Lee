/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int max_num = 0;
        unordered_map<int, int> h;
        for(auto e : nums) 
        {
            max_num = max(max_num, e);
            h[e] ++;
        }
        int n = nums.size();

        vector<vector<int>> f(max_num + 1, vector<int>(2, 0));

        for(int i = 1; i <= max_num; i++)
        {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            if(h.find(i) != h.end())
                f[i][1] = f[i - 1][0] + i * h[i];
        }

        return max(f[max_num][0], f[max_num][1]);
    }
};
// @lc code=end

