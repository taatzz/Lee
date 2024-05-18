/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<int> st(n + 1);

        auto find = [&]()
        {
            for(int i = 2; i < n; i++)
            {
                if(!st[i]) 
                {
                    res++;
                    for(int j = i; j < n; j += i) st[j] = 1;
                }
            }
        };

        find();

        return res;
    }
};
// @lc code=end

