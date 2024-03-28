/*
 * @lc app=leetcode.cn id=2508 lang=cpp
 *
 * [2508] 添加边使所有节点度数都为偶数
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static const int N = 100010;
    int in[N];

    bool isPossible(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> h;

        for(auto& e : edges)
        {
            int a = e[0], b = e[1];
            h[a].insert(b);
            h[b].insert(a);
            in[a]++, in[b]++;
        }

        int cnt = 0;
        vector<int> t;
        for(int i = 1; i <= n; i++)
            if(in[i] % 2 == 1) 
            {
                cnt++;
                t.push_back(i);
            }

        // 分类讨论，奇数节点 cnt
        // cnt == 0 已经符合
        // cnt == 2 别的节点都已经是偶数，那么就需要寻找一个点和剩余的两个点都没有边
        // cnt == 4 四个节点两两连边，剩余的是否可以连边
        // 因为不能又自环，所以其它情况都是无法满足的
        if(cnt == 0) return 1;
        else if(cnt > 4 || cnt % 2 == 1) return false;
        else if(cnt == 2)
        {
            for(int i = 1; i <= n; i++)
            {
                if(!h[i].count(t[0]) && !h[i].count(t[1])) return true;
            }
        }

        for(int i = 0; i < t.size(); i++)
        {
            for(int j = i + 1; j < t.size(); j++)
            {
                if(h[t[i]].find(t[j]) == h[t[i]].end())
                {
                    int a = 0, b = 0;
                    for(int k = 0; k < t.size(); k++)
                    {
                        if(k != i && k != j)
                        {
                            if(a == 0) a = t[k];
                            else b = t[k];
                        }
                    }
                    if(h[a].find(b) == h[a].end()) return true;
                }
            }
        }

        return 0;
    }
};
// @lc code=end

