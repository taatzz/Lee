/*
 * @lc app=leetcode.cn id=2090 lang=cpp
 *
 * [2090] 半径为 k 的子数组平均值
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    long long s[N];

    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];

        vector<int> res(n);
        for(int i =  0; i < n; i++)
        {
            int left = i - k, right = i + k;
            if(left < 0 || right >= n) 
            {
                res[i] = -1;
                continue;
            }
            res[i] = (s[right + 1] - s[left]) / (2 * k + 1);
        }

        return res;
    }
};
// @lc code=end

