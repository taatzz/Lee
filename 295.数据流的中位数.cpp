/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
#include <queue>

using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> r; // 右半部分小顶堆
    priority_queue<int, vector<int>, less<int>> l; //左半部分大顶堆

    MedianFinder() {

    }
    
    void addNum(int num) {
        // 我们让左边的数量比右边的数量多一，那么当两部分相等时答案就是两堆顶的平均数，否则就是左堆顶
        // 插入时，如果插入前的数量是相同的：
        //         如果右边数量等于0，说明是第一次插入，直接插入到左边
        //         如果待插入数字小于右边的堆顶，直接插入即可，因为我们的规则是左边比右边多一
        //         如果待插入数字大于右边的堆顶，这是需要插入到右边，但是插入之后不符合规则，所以先将堆顶插入到左边，继续满足相等
        // 如果插入前的数量不相等：
        //         如果待插入数字小于右边的堆顶，这时需要插入到左边，但是数量不相等，所以需要将左边的堆顶，插入到右边，然后数量相等
        //         如果待插入数字大于右边的堆顶，这时就直接插入到右堆

        if(l.size() == r.size())
        {
            if(r.size() == 0 || num <= r.top())
            {
                l.push(num);
            }
            else if(num > r.top())
            {
                l.push(r.top());
                r.pop();
                r.push(num);
            }
        }
        else
        {
            if(l.top() <= num) r.push(num);
            else
            {
                r.push(l.top());
                l.pop();
                l.push(num);
            }
        }
    }
    
    double findMedian() {
        if(l.size() == r.size()) return (l.top() + r.top()) / 2.0;
        else return l.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

