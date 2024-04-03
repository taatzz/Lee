/*
 * @lc app=leetcode.cn id=2751 lang=cpp
 *
 * [2751] 机器人碰撞
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class Solution{
public:
    typedef pair<int, int> pii;

    vector<int> survivedRobotsHealths(vector<int>& nums, vector<int>& healths, string s) {
        int n = nums.size();
        vector<pii> t;
        for(int i = 0; i < n; i++) t.push_back({nums[i], i});
        sort(t.begin(), t.end());
        stack<int> st;

        for(int i = 0; i < n; i++)
        {
            // 向右的直接入栈
            if(s[t[i].second] == 'R') st.push(t[i].second);
            else
            {
                while(st.size())
                {
                    int tmp = st.top();

                    // 当前机器人血量高于栈顶的血量，移除栈顶，继续匹配
                    if(healths[t[i].second] > healths[tmp]) 
                    {
                        st.pop();
                        healths[t[i].second]--;
                        healths[tmp] = 0;
                    }
                    else if(healths[t[i].second] == healths[tmp]) // 相等 移除栈顶，血量归零
                    {
                        st.pop();
                        healths[t[i].second] = 0;
                        healths[tmp] = 0;
                        break;
                    }
                    else // 栈顶的血量高，右边的血量归零，停止匹配
                    {
                        healths[tmp]--;
                        healths[t[i].second] = 0;
                        break;
                    }
                }
            }
        }

        vector<int> res;
        for(int i = 0; i < n; i++) 
            if(healths[i] != 0) res.push_back(healths[i]);

        return res;
    }
};
// @lc code=end

