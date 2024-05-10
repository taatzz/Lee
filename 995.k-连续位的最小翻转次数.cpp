/*
 * @lc app=leetcode.cn id=995 lang=cpp
 *
 * [995] K 连续位的最小翻转次数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int s[N];

    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int pre = 0, res = 0;
        for(int i = 0; i < n; i++)
        {
            pre += s[i];
            if((nums[i] + pre) % 2 == 0)
            {
                if(i + k > n) return -1;
                s[i] ++;
                s[i + k]--;
                pre++; // 更新一下当前位置的差分前缀和
                res++;
            } 
        }

        return res;
    }
};
// @lc code=end

