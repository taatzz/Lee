/*
 * @lc app=leetcode.cn id=2766 lang=cpp
 *
 * [2766] 重新放置石块
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> h(nums.begin(), nums.end());

        for(int i = 0; i < moveFrom.size(); i++)
        {
            h.erase(moveFrom[i]);
            h.insert(moveTo[i]);
        }

        return vector<int>(h.begin(), h.end());
    }
};
// @lc code=end

