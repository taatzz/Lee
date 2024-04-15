/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */

// @lc code=start
#include <unordered_map>

using namespace std;

class MyHashMap {
public:
    unordered_map<int, int> h;

    MyHashMap() {

    }
    
    void put(int key, int value) {
        h[key] = value;
    }
    
    int get(int key) {
        if(h.find(key) == h.end()) return -1;
        return h[key];
    }
    
    void remove(int key) {
        h.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

