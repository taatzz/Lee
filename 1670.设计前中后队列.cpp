/*
 * @lc app=leetcode.cn id=1670 lang=cpp
 *
 * [1670] 设计前中后队列
 */

// @lc code=start
#include <vector>
#include <deque>

using namespace std;

class FrontMiddleBackQueue {
public:
    deque<int> left;
    deque<int> right;
    deque<int> dq;
    int sz = 0;
    FrontMiddleBackQueue() {

    }
    
    void pushFront(int val) {
        dq.push_front(val);
        sz++;
    }
    
    void pushMiddle(int val) {
        int mid = sz / 2;
        vector<int> tmp;
        while(mid --) 
        {
            tmp.push_back(dq.front());
            dq.pop_front();
        }
        dq.push_front(val);
        sz++;
        for(int i = tmp.size() - 1; i >= 0; i-- )dq.push_front(tmp[i]);
    }
    
    void pushBack(int val) {
        dq.push_back(val);
        sz++;
    }
    
    int popFront() {
        if(!sz) return -1;

        int t = dq.front();
        dq.pop_front();
        sz--;

        return t;
    }
    
    int popMiddle() {
        if(!sz) return -1;
        
        int mid = (sz - 1) / 2;
        vector<int> tmp;
        while(mid --)
        {
            tmp.push_back(dq.front());
            dq.pop_front();
        }
        int t = dq.front();
        dq.pop_front();
        sz--;
        for(int i = tmp.size() - 1; i >= 0; i--)dq.push_front(tmp[i]);
        return t;
    }
    
    int popBack() {
        if(!sz) return -1;
        int t = dq.back();
        dq.pop_back();
        sz--;

        return t;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end

