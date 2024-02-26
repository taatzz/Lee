/*
 * @lc app=leetcode.cn id=955 lang=cpp
 *
 * [955] 删列造序 II
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 贪心 首先考虑所有的列都不选择，那么如果有一列是符合我们的要求的就应该直接选上
    // 然后考虑选完一列，首先选完一列之后有的列的大小关系就是已经确认的，所以我们用一个数组保存确切的大小关系
    // 对于已经确认的那么后面的都是可以选择的，如果前面列是相同的就去比较后面的列，后面的列符合<=就继续选
    // 最后答案就是总数减去选中的

    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), res = 0;

        // 1 < 2 ==
        vector<int> st;
        for(int j = 0; j < strs[0].size(); j++)
        {
            bool flag = true;
            vector<int> tmp(n);
            for(int i = 0; i < n - 1; i++)
            {
                if(strs[i][j] < strs[i + 1][j])
                {
                    tmp[i] = 1;
                }
                else if(strs[i][j] == strs[i + 1][j])
                {
                    tmp[i] = 2;
                }
                else
                {
                    tmp[i] = 3;
                    flag = false;
                }
            }
            // 第一列直接赋值
            if(flag && st.size() == 0) 
            {
                res ++;
                st = tmp;
            }
            else if(st.size())
            {
                int i = 0;
                for(; i < n; i++)
                {
                    // 前面已经确认关系的不用比较
                    if(st[i] == 1) 
                    {
                        tmp[i] = 1;
                        continue;
                    }
                    if(st[i] == 2 && tmp[i] == 3) break;
                }
                // 这一列同样可以选择
                if(i == n) 
                {
                    res ++;
                    // 更新一下大小情况
                    st = tmp;
                }
            }
        }

        return strs[0].size() - res;
    }
};
// @lc code=end

