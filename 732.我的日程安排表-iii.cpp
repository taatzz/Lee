/*
 * @lc app=leetcode.cn id=732 lang=cpp
 *
 * [732] 我的日程安排表 III
 */

// @lc code=start
#include <map>

using namespace std;

class MyCalendarThree {
public:
    map<int, int> h;
    MyCalendarThree() {

    }
    
    int book(int startTime, int endTime) {
        int res = 0;
        h[startTime]++, h[endTime]--;
        int k = 0;
        for(auto& [_, e] : h)
        {
            k += e;
            res = max(res, k);
        }

        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
// @lc code=end

