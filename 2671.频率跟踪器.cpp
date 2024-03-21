/*
 * @lc app=leetcode.cn id=2671 lang=cpp
 *
 * [2671] 频率跟踪器
 */

// @lc code=start
#include <unordered_map>
#include <unordered_multiset>

using namespace std;

class FrequencyTracker {
public:
    unordered_map<int, int> h;
    unordered_multiset<int> s;

    FrequencyTracker() {
        
    }
    
    void add(int number) {
        int& x = h[number];

        if(x > 0) s.erase(s.find(x));
        x++;
        s.insert(x);
    }
    
    void deleteOne(int number) {
        int& x = h[number];

        if(x == 0) return;

        s.erase(s.find(x));
        x--;
        if(x > 0) s.insert(x);
    }
    
    bool hasFrequency(int frequency) {
        return s.find(frequency) != s.end();
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
// @lc code=end

