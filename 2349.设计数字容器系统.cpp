/*
 * @lc app=leetcode.cn id=2349 lang=cpp
 *
 * [2349] 设计数字容器系统
 */

// @lc code=start
#include <unordered_map>
#include <set>

using namespace std;

class NumberContainers {
public:
    unordered_map<int, set<int>> num_idx;
    unordered_map<int, int> idx_num;
    NumberContainers() {

    }
    
    void change(int index, int number) {
        if(idx_num.find(index) != idx_num.end())
        {
            int x = idx_num[index];
            num_idx[x].erase(index);
            if(num_idx[x].size() == 0) num_idx.erase(x);
            idx_num[index] = number;
            num_idx[number].insert(index);
        }
        else
        {
            idx_num[index] = number;
            num_idx[number].insert(index);
        }
    }
    
    int find(int number) {
        if(num_idx.find(number) == num_idx.end()) return -1;
        else return *(num_idx[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
// @lc code=end

