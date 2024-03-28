/*
 * @lc app=leetcode.cn id=2197 lang=cpp
 *
 * [2197] 替换数组中的非互质数
 */

// @lc code=start
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> stk;

        int n = nums.size();
        stk.push(nums[0]);
        for(int i = 1; i < n; i++)
        {
            stk.push(nums[i]);
            while(stk.size() > 1)
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int g = gcd(a, b);
                if(g == 1) 
                {
                    stk.push(b);
                    stk.push(a);
                    break;
                }
                stk.push((long long)a * b / g);
            }
        }

        vector<int> res;
        while(stk.size())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end

