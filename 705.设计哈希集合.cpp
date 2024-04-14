/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */

// @lc code=start
#include <set>

using namespace std;

class MyHashSet {
public:
    multiset<int> h;

    MyHashSet() {

    }
    
    void add(int key) {
        h.insert(key);
    }
    
    void remove(int key) {
        h.erase(key);
    }
    
    bool contains(int key) {
        return h.find(key) != h.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

