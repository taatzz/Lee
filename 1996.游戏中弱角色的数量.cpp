/*
 * @lc app=leetcode.cn id=1996 lang=cpp
 *
 * [1996] 游戏中弱角色的数量
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    // 贪心排序：如果第一维相同就贪心的将最大的放在最前面，看后续第一维不相同的是否大于前面的元素
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0] || (a[0] == b[0] && a[1] >= b[1]);
    }

    int numberOfWeakCharacters(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), cmp);

        stack<int> st;
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            // 单调递减栈维护第二维不同
            while(st.size() && nums[st.top()][1] < nums[i][1] && nums[st.top()][0] != nums[i][0])
            {
                res++;
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};
// @lc code=end

