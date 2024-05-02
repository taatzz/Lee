/*
 * @lc app=leetcode.cn id=2747 lang=cpp
 *
 * [2747] 统计没有收到请求的服务器数目
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef pair<int, int> pii;

    vector<int> countServers(int n, vector<vector<int>>& nums, int x, vector<int>& queries) {
        sort(nums.begin(), nums.end(),
        [&](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        vector<pii> t;
        for(int i = 0; i < queries.size(); i++)
        {
            t.emplace_back(queries[i], i);
        }
        sort(t.begin(), t.end());

        vector<int> res(queries.size()), cnt(n + 1);
        int sum = 0, l = 0, r = 0;
        for(auto& [k, idx] : t)
        {
            while(r < nums.size() && nums[r][1] <= k)
                if(cnt[nums[r++][0]]++ == 0) sum++;

            while(l < nums.size() && nums[l][1] < k - x)
                if(-- cnt[nums[l++][0]] == 0) sum--;

            res[idx] = n - sum;
        }
        return res;
    }
};
// @lc code=end

