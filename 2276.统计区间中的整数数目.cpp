/*
 * @lc app=leetcode.cn id=2276 lang=cpp
 *
 * [2276] 统计区间中的整数数目
 */

// @lc code=start
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class CountIntervals {
public:
    typedef pair<int, int> PII;
    set<PII> cont; // [right, left]
    int size = 0;

    CountIntervals() {

    }
    
    void add(int left, int right) {
        if(left >= right + 1) return;
        // int prev = size;
        int addleft = left, addright = right + 1;
        for(auto p = cont.lower_bound({left, INT_MIN}); p != cont.end() && p->second <= right + 1; )
        {
            addright = max(addright, p->first);
            addleft = min(addleft, p->second);
            size -= p->first - p->second;
            p = cont.erase(p);
        }
        size += addright - addleft;
        cont.insert({addright, addleft});
    }
    
    int count() {
        return size;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
// @lc code=end

