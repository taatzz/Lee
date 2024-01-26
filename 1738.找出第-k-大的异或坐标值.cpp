/*
 * @lc app=leetcode.cn id=1738 lang=cpp
 *
 * [1738] 找出第 K 大的异或坐标值
 */

// @lc code=start
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& nums, int k) {
        int m = nums.size(), n = nums[0].size();
        vector<vector<int>> s(m + 1, vector<int>(n + 1));

        vector<int> t;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                s[i][j] = s[i - 1][j] ^ s[i][j - 1] ^ s[i - 1][j - 1] ^ nums[i - 1][j - 1];
                t.push_back(s[i][j]);
            }
        }
        
        sort(t.begin(), t.end(), greater<int>());

        return t[k - 1];
    }
};
// @lc code=end

