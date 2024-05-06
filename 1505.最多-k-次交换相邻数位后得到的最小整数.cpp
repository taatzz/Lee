/*
 * @lc app=leetcode.cn id=1505 lang=cpp
 *
 * [1505] 最多 K 次交换相邻数位后得到的最小整数
 */

// @lc code=start
#include <vector>
#include <set>
#include <string>

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
        {
            tr[i] += c;
        }
    }

    int query(vector<int>& tr, int x)
    {
        int res = 0;
        if(x < 0) x = 0;
        for(int i = x; i; i -= lowbit(i))   
            res += tr[i];

        return res;
    }

    string minInteger(string num, int k) {
        set<int> t[10];
        for(int i = 0; i < num.size(); i++)
        {
            t[num[i] - '0'].insert(i + 1);
        }

        int n = num.size();
        vector<int> tr(n + 1);

        int i = 0;
        string res;
        for(i = 1; i <= n; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(t[j].size())
                {
                    int x = query(tr, n) - query(tr, *t[j].begin());
                    int dist = *t[j].begin() + x - i;
                    if(dist <= k)
                    {
                        insert(tr, *t[j].begin(), 1);
                        t[j].erase(t[j].begin());
                        res += '0' + j;
                        k -= dist;
                        break;
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end

