/*
 * @lc app=leetcode.cn id=731 lang=cpp
 *
 * [731] 我的日程安排表 II
 */

// @lc code=start
#include <map>

using namespace std;

class MyCalendarTwo {
public:
    map<int, int> h;
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        h[start]++, h[end]--;

        bool flag = 1;
        int res = 0;
        for(auto& [_, e] : h)
        {
            res += e;
            if(res >= 3) flag = 0;
        }
        if(!flag) 
        {
            h[start] --;
            h[end]++;
        }

        return flag;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

