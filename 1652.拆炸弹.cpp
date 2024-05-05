/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n);
        if(k == 0) return vector<int> (n, 0);
        else if(k > 0)
        {
            for(int i = 0; i < n; i++)
            {
                int sum = 0;
                for(int j = 1; j <= k; j++)
                {
                    sum += nums[(i + j) % n];
                }
                res[i] = sum;
            }
        }
        else 
        {
            for(int i = 0; i < n; i++)
            {
                int sum = 0;
                for(int j = -1; j >= k; j--)
                {
                    sum += nums[(i + j + n) % n];
                }
                res[i] = sum;
            }
        }

        return res;
    }
};
// @lc code=end

