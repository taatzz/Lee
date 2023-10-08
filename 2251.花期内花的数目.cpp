/*
 * @lc app=leetcode.cn id=2251 lang=cpp
 *
 * [2251] 花期内花的数目
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons) {
        int n = flowers.size();
        vector<int> starts(n), ends(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = flowers[i][0];
            ends[i] = flowers[i][1];
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int m = persons.size();
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            // 找到第一个大于num的位置
            int x = upper_bound(starts.begin(), starts.end(), persons[i]) - starts.begin();
            // 找到第一个大于num的位置
            int y = lower_bound(ends.begin(), ends.end(), persons[i]) - ends.begin();
            ans[i] = x - y;
        }
        return ans;
    }
};
// @lc code=end

