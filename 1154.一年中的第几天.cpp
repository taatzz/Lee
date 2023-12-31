/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 *
 * [1154] 一年中的第几天
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    bool check(int y)
    {
        if(y % 4 == 0 && y % 100 != 0 || (y % 400 == 0))
            return true;
        return false;
    }

    int dayOfYear(string date) {
        int year, month, day;
        year = stoi(date.substr(0, 4));
        month = stoi(date.substr(5, 2));
        day = stoi(date.substr(8, 2));

        int res = 0;
        for(int i = 1; i < month; i++)
        {
            if(i == 2 && check(year)) res += 1;
            res += days[i];
        }

        return res + day;
    }
};
// @lc code=end

