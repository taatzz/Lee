/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
            while(q1.size() > 0 && q1.size() != 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int tmp = q1.front();
            q1.pop();
            if(!q2.empty())
                q1 = q2;

            return tmp;
    }
    
    int top() {
            while(q1.size() > 0 && q1.size() != 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int tmp = q1.front();
            q2.push(q1.front());
            q1.pop();
            q1 = q2;
            return tmp;
    }
    
    bool empty() {
        if(q1.size() == 0 && q2.size() == 0)
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

