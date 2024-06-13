/*
 * @lc app=leetcode.cn id=2813 lang=cpp
 *
 * [2813] 子序列最大优雅度
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& nums, int k) {
        sort(nums.begin(), nums.end(),
        [](vector<int>& a, vector<int>& b) {return a[0] > b[0];});

        int n = nums.size();
        long long res = 0, sum = 0;
        unordered_set<int> h;
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            int a = nums[i][0], b = nums[i][1];
            // 前k个类别中可以选择的利润最大
            if(i < k)
            {
                sum += a;
                // 类别重复选择将重复的利润保存
                if(h.count(b)) st.push(a);
                else h.insert(b);
            }
            else if(st.size() && !h.count(b))
            {
                // 后面的元素遇到一个前面没有选择的类别就把前面最小的一个利润删除。
                sum += a - st.top();
                h.insert(b);
                st.pop();
            }
            res = max(res, sum + (long long)h.size() * (long long) h.size());
        }

        return res;
    }
};
// @lc code=end

