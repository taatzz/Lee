/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // 最大矩形的面积宽为矩形两端小于当前矩形的差
    // 当前矩形的面积为当前矩形的高*宽
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // 右边界初始化为n表示哨兵位，（处理右边界和单调递增的情况）
        vector<int> left(n), right(n, n); // 保存当前矩形两端小于自己的矩形位置
        
        // 单调递增栈
        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            // 当前元素小于当前的栈顶元素表示栈顶元素的右边界为当前元素
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                right[mono_stack.top()] = i;
                mono_stack.pop();
            }
            // 当前元素大于栈顶元素表示当前的元素的左边界为栈顶元素或者数组边界
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            // 面积 = 高*宽
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};
// @lc code=end

