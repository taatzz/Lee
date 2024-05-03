/*
 * @lc app=leetcode.cn id=1803 lang=cpp
 *
 * [1803] 统计异或值在范围内的数对有多少
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 20010;
    int son[N * 20][2], idx, cnt[N * 20];

    void insert(int x)
    {
        int p = 0;
        for(int i = 15; i >= 0; i--)
        {
            int u = x >> i & 1;
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
            cnt[p]++;
        }
        
    }

    int query(int x, int limit)
    {
        int p = 0;
        int res = 0;
        for(int i = 15; i >= 0; i--)
        {
            int u = x >> i & 1;
            // 最大限制当前位是1时，那么x和其它数异或结果可以0或1
            if(limit >> i & 1) 
            {
                // 如果当前位置是0那么一定就不会超出限制，那么直接加到答案
                // 直接将当前位置为0的数量加到答案
                res += cnt[son[p][u]];
                // 当前异或为1的路径为空就返回
                if(!son[p][!u]) return res;
                // 继续当前异或位置为1的路径
                p = son[p][u ^ 1];
            }
            else 
            {
                // 限制的位置是0就必须是0，如果没有就返回答案
                if(!son[p][u]) return res;
                p = son[p][u];
            }
        }

        return res;
    }


    int countPairs(vector<int>& nums, int low, int high) {
        int res = 0;
        for(auto& e : nums)
        {
            // 找到限制为[0,high + 1} 和 [0, low], 那么答案就是两个区间相减
            res += query(e, high + 1) - query(e, low);
            insert(e);
        }

        return res;
    }
};
// @lc code=end

