/*
 * @lc app=leetcode.cn id=2076 lang=cpp
 *
 * [2076] 处理含限制条件的好友请求
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    static const int N = 1010;
    int p[N];

    int find(int x)
    {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        for(int i = 0; i < n; i++) p[i] = i;
        unordered_map<int, unordered_set<int>> h;

        for(auto& e : restrictions)
        {
            int a = e[0], b = e[1];
            h[a].insert(b);
            h[b].insert(a);
        }

        vector<bool> res;
        for(auto& e : requests)
        {
            int a = e[0], b = e[1];
            a = find(a), b = find(b);
            if(!h[a].count(b))
            {
                res.push_back(1);
                if(a != b) p[a] = b;
                for(int e : h[a])
                {
                    h[b].insert(e);
                    h[e].erase(a);
                    h[e].insert(b);
                }
            }
            else res.push_back(0);
        }

        return res;
    }
};
// @lc code=end

