/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
    inline pair<int, int> op(int type, const pair<int, int> &state, int x, int y) {
        switch(type) {
            case 0 : return make_pair(x, state.second);
            case 1 : return make_pair(state.first, y);
            case 2 : return make_pair(0, state.second);
            case 3 : return make_pair(state.first, 0);
            case 4 :{
                int move = min(state.first, y-state.second);
                return make_pair(state.first - move, state.second + move);
            }
            case 5 : {
                int move = min(x-state.first, state.second);
                return make_pair(state.first + move, state.second - move);
            }
        }
        return make_pair(0,0);
    }
    struct HashPair {
        size_t operator()(const pair<int, int> &key) const noexcept
	    {
		    return (size_t(key.first)<<31) | size_t(key.second);
	    }
    };
    inline int64_t Hash(int x, int y) {
        return int64_t(x) << 32 | y;
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z) {   //加了一个很蠢的剪枝，作用比较大。
            return false;
        }
        unordered_set<int64_t> mark; //pair<int, int> 换成int64_t, 但是意义不大。
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        while(q.empty() == false) {
            auto f = q.front();
            q.pop();
            if(f.first + f.second == z) {
                return true;
            }
            for(int i = 0; i < 6; i++) {
                auto next = op(i, f, x, y);
                int64_t h = Hash(next.first, next.second);
                if(mark.find(h) != mark.end()) {
                    continue;
                }
                mark.insert(h);
                q.push(next);
            }
        }
        return false;
    }
};
// @lc code=end

