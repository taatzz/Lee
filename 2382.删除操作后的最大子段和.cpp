/*
 * @lc app=leetcode.cn id=2382 lang=cpp
 *
 * [2382] 删除操作后的最大子段和
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int p[N];

    int find(int x)
    {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        vector<long long> res(n);
        for(int i = 1; i <= nums.size(); i++) p[i] = i;

        vector<long long> sum(nums.size() + 10);
        for(int i = n - 1; i > 0; i--)
        {
            int x = removeQueries[i];

            int to = find(x + 1);
            p[x] = to;
            sum[to] += sum[x] + nums[x];
            res[i - 1] = max(res[i], sum[to]);
        }

        return res;
    }
};
// @lc code=end

