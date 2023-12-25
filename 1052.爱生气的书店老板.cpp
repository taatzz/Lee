/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(grumpy[i] == 0) sum += customers[i];
        }

        int res = 0, t = 0;
        for(int i = 0; i < n; i++)
        {
            if(grumpy[i] == 1) t += customers[i];
            if(i >= minutes - 1)
            {
                res = max(res, sum + t);
                int j = i - minutes + 1;
                if(grumpy[j] == 1) t -= customers[j];
            }
        }

        return res;
    }
};
// @lc code=end

