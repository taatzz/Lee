/*
 * @lc app=leetcode.cn id=2798 lang=cpp
 *
 * [2798] 满足目标工作时长的员工数目
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        sort(hours.begin(), hours.end());

        return hours.end() - lower_bound(hours.begin(), hours.end(), target);
    }
};
// @lc code=end

