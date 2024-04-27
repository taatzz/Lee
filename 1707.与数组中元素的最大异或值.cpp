/*
 * @lc app=leetcode.cn id=1707 lang=cpp
 *
 * [1707] 与数组中元素的最大异或值
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static const int N = 100010, M = 32 * N;
    int son[M][2], idx;

    void insert(int x)
    {
        int p = 0;
        for(int i = 31; i >= 0; i--)
        {
            int u = (x >> i & 1);
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
    }

    int query(int x)
    {
        int p = 0, res = 0;
        for(int i = 31; i >= 0; i--)
        {
            int u = (x >> i & 1);
            if(son[p][!u]) 
            {
                res += (1 << i);
                p = son[p][!u];
            }
            else p = son[p][u];
        }

        return res;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        memset(son, 0, sizeof son);
        // 离线查询，将小于查询的值全部插入字典树，然后再按照最大异或对处理
        sort(nums.begin(), nums.end());
        int pos = 0;
        for(auto& e : queries)
        {
            e.push_back(pos++);
        }
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b)
        { return a[1] < b[1]; });
        

        vector<int> res(queries.size());
        int cur = 0;
        for(auto& e : queries)
        {
            int a = e[0], b = e[1], id = e[2];
            while(cur < nums.size() && nums[cur] <= b)
            {
                insert(nums[cur]);
                cur++;
            }
            if(cur == 0) res[id] = -1;
            else res[id] = query(a);
        }

        return res;
    }
};
// @lc code=end

