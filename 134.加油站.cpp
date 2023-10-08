/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            sum += gas[i] - cost[i];
        }
        if(sum < 0) return -1;

        int cursum = 0, start = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            cursum += gas[i] - cost[i];
            if(cursum < 0)
            {
                start = i + 1;
                cursum = 0;
            }
        }
        return start;
    }
};
// @lc code=end

