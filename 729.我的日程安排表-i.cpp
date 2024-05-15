/*
 * @lc app=leetcode.cn id=729 lang=cpp
 *
 * [729] 我的日程安排表 I
 */

// @lc code=start
#include <map>

using namespace std;

class MyCalendar {
public:
    map<int, int> h;
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        h[start]++, h[end]--;

        bool flag = 1;
        int res = 0;
        for(auto& [_, e] : h)
        {
            res += e;
            if(res > 1) flag = 0;
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
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

