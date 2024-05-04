/*
 * @lc app=leetcode.cn id=1409 lang=cpp
 *
 * [1409] 查询带键的排列
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:

    int lowbit(int x)
    {
        return x & -x;
    }

    void insert(vector<int>& tr, int x, int c)
    {
        for(int i = x; i < tr.size(); i += lowbit(i))
            tr[i] += c;
    }

    int query(vector<int>& tr, int x)
    {
        int res = 0;
        for(int i = x; i; i -= lowbit(i))
            res += tr[i];

        return res;
    }

    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> tr(m + 1);
        for(int i = 1; i <= m; i++)
        {
            insert(tr, i, i);
        }

        vector<int> res;
        for(auto& e : queries)
        {
            int x = query(tr, e) - query(tr, e - 1);
            res.push_back(x - 1);
            
            for(int i = 1; i <= m; i++)
            {
                int t = query(tr, i) - query(tr, i - 1);
                if(t < x)
                {
                    insert(tr, i, 1);
                }
            }
            insert(tr, e, 1 - x);
        }

        return res;
    }
};
// @lc code=end

