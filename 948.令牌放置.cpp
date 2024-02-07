/*
 * @lc app=leetcode.cn id=948 lang=cpp
 *
 * [948] 令牌放置
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 1010;
    bool st[N];

    // 能买就一直买，如果买不了就去换能量然后统计最大值
    int bagOfTokensScore(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 0 || k < nums[0]) return 0;

        int hp = 0, res = 0;
        for(int i = 0, j = n - 1; i <= j;)
        {
            if(k >= nums[i])
            {
                hp++;
                k -= nums[i++];
                res = max(res, hp);
            }
            else if(k < nums[i] && hp > 0)
            {
                hp --;
                k += nums[j--];
            }
            else break;
        }

        return res;
    }
};
// @lc code=end

