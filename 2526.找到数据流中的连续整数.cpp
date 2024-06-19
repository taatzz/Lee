/*
 * @lc app=leetcode.cn id=2526 lang=cpp
 *
 * [2526] 找到数据流中的连续整数
 */

// @lc code=start
#include <queue>
#include <unordered_map>

using namespace std;

class DataStream {
public:
    int _k, v;
    unordered_map<int, int> h;
    queue<int> q;
    DataStream(int value, int k) {
        _k = k, v = value;
    }
    
    bool consec(int num) {  
        if(q.size() == _k)
        {
            int x = q.front();
            q.pop();
            h[x]--;
            if(h[x] == 0)
                h.erase(x);
        }
        q.push(num);
        h[num]++;

        if(h.size() != 1) return false;
        else
        {
            if(h.begin()->second == _k && h.begin()->first == v) return 1;
            else return 0;
        }
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
// @lc code=end

