/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 *
 * [1185] 一周中的第几天
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    string res[7] = { "Sunday","Monday","Tuesday","Wednesday",
                    "Thursday","Friday","Saturday" };

    bool check(int year)
    {
        if((year % 4 == 0 && year % 100 != 0) && (year % 400 == 0))
            return 1;
        return 0;
    }

    string dayOfTheWeek(int day, int month, int year) {
        int t = 4;
        for(int i = 1971; i < year; i++)
            t += check(i) ? 366 : 365;
        

        for(int i = 1; i < month; i++)
        {
            if(i == 2 && check(year)) t += 1;
            t += m[i];
        }
        t += day;

        return res[t % 7];
    }
};
// @lc code=end

