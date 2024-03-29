/*
 * @lc app=leetcode.cn id=855 lang=cpp
 *
 * [855] 考场就座
 */

// @lc code=start
#include <set>

using namespace std;

class ExamRoom {
public:
    set<int> h;
    int _n;
    ExamRoom(int n) {
        _n = n;
    }
    
    int seat() {
        if(h.size() == 0)
        {
            h.insert(0);
            return 0;
        }
        int l = -1, r = 0, mx = 0, res = 0;
        if(*h.begin() != 0) mx = (*h.begin());
        for(auto& e : h)
        {
            r = e;
            if(mx < (r - l) / 2)
            {
                mx = (r - l) / 2;
                res = l + (r - l) / 2;
            }
            l = r;
        }
        if(r != _n - 1)
        {
            if(mx < _n - 1 - r) res = _n - 1;
        }
        h.insert(res);

        return res;
    }
    
    void leave(int p) {
        h.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end

