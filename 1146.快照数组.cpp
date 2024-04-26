/*
 * @lc app=leetcode.cn id=1146 lang=cpp
 *
 * [1146] 快照数组
 */

// @lc code=start
#include <unordered_map>
#include <map>

using namespace std;

class SnapshotArray {
public:
    unordered_map<int, map<int, int>> h; // 每个下标对应的快照编号为多少时的值
    int idx = 0;

    SnapshotArray(int length) {

    }
    
    void set(int index, int val) {
        h[index][idx] = val;
    }
    
    int snap() {

        return idx++;
    }
    
    int get(int index, int snap_id) {
        if(!h.count(index)) return 0;
        // 寻找snap_id 的最后一次修改，那么就相当于找到snap_id + 1 前的一次修改
        auto it = h[index].lower_bound(snap_id + 1);
        return it == h[index].begin() ? 0 : (--it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end

