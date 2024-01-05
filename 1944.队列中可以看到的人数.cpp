/*
 * @lc app=leetcode.cn id=1944 lang=cpp
 *
 * [1944] 队列中可以看到的人数
 */

// @lc code=start
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> res(n, 0);

        for(int i = 0; i < n; i++)
        {
            // 右边的人比当前人矮后面的人也看不到就直接删除，但是当前人可以看到所以循环几次加几次
            while(!st.empty() && heights[st.top()] <= heights[i])
            {
                st.pop();
                res[i]++;
            }
            // 当栈不为空时栈顶元素就是当前人看到最后一个人
            if(!st.empty()) res[i]++;
            st.push(i);
        }

        return res;
    }
};
// @lc code=end

