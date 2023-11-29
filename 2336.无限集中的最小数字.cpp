/*
 * @lc app=leetcode.cn id=2336 lang=cpp
 *
 * [2336] 无限集中的最小数字
 */

// @lc code=start
#include <set>

using namespace std;

class SmallestInfiniteSet {
public:
    set<int> small;
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++)
            small.insert(i);
    }
    
    int popSmallest() {
        if(!small.size()) return -1;
        int t = *(small.begin());
        small.erase(t);
        return t;
    }
    
    void addBack(int num) {
        if(small.find(num) == small.end())
            small.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end

