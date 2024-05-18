/*
 * @lc app=leetcode.cn id=2644 lang=cpp
 *
 * [2644] 找出可整除性得分最大的整数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& arr) {
        int n = nums.size(), m = arr.size();

        int res = 0, mx = -1;
        for(int j = 0; j < m; j++)
        {
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if(nums[i] % arr[j] == 0) cnt++;
            }
            if(cnt > mx) res = arr[j], mx = cnt;
            else if(cnt == mx) res = min(res, arr[j]); 
        }

        return res;
    }
};
// @lc code=end

