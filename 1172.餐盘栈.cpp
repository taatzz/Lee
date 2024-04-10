/*
 * @lc app=leetcode.cn id=1172 lang=cpp
 *
 * [1172] 餐盘栈
 */

// @lc code=start
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class DinnerPlates {
public:
    int c;
    vector<stack<int>> p;
    priority_queue<int, vector<int>, greater<int>> q; // 保存从小到大的未满的栈

    DinnerPlates(int capacity) : c(capacity){

    }
    
    void push(int val) {
        // 最小的栈都已经大于当前的栈的数量，全部清空
        if(q.size() && q.top() >= p.size())
            while(q.size()) q.pop();

        // 堆为空，全部栈都是满的
        if(q.size() == 0)
        {
            // 创建一个新栈
            stack<int> s;
            s.push(val);
            p.push_back(s);
            // 栈未满加入堆
            if(c > 1)
                q.push(p.size() - 1);          
        }
        else
        {
            // 从左到右得第一个未满栈
            auto& st = p[q.top()];
            st.push(val);
            if(st.size() == c) q.pop();
        }
    }
    
    int pop() {
        // 等价于删除最大栈得栈顶
        return popAtStack(p.size() - 1);
    }
    
    int popAtStack(int index) {
        // 非法操作
        if(index < 0 || index >= p.size() || p[index].size() == 0) return -1;

        auto& st = p[index];
        // 满栈，删除之后不满
        if(st.size() == c)
        {
            q.push(index);
        }
        int val = st.top();
        st.pop();

        // 将结尾得空栈删除
        while(p.size() && p.back().size() == 0) p.pop_back();

        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
// @lc code=end

