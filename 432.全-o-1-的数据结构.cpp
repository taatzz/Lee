/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class AllOne {
public:
    unordered_map<string, int> h;
    set<pair<int, string>> res;
    AllOne() {

    }
    
    void inc(string s) {
        if(h.count(s))
        {   
            pair<int, string> t = {h[s], s};
            res.erase(t);
        }
        h[s]++;
        res.insert({h[s], s});
    }
    
    void dec(string s) {
        pair<int, string> t = {h[s], s};
        res.erase(t);
        h[s]--;
        if(h[s])
            res.insert({h[s], s});
        else
            h.erase(s);
    }
    
    string getMaxKey() {
        if(res.size() == 0) return "";
        return res.rbegin()->second;
    }
    
    string getMinKey() {
        if(res.size() == 0) return "";
        return res.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

