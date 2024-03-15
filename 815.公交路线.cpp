/*
 * @lc app=leetcode.cn id=815 lang=cpp
 *
 * [815] 公交路线
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;

        unordered_map<int, vector<int>> h;
        for(int i = 0; i < routes.size(); i++)
        {
            for(auto& e : routes[i])
                h[e].push_back(i);
        }


        vector<bool> st(routes.size(), 0);
        queue<int> q;
        q.push(source);

        int res = 0;
        while(q.size())
        {
            res++;
            int size = q.size();
            while(size--)
            {
                int cur = q.front();
                q.pop();
                for(int& route : h[cur])
                {
                    if(!st[route])
                    {
                        st[route] = true;
                        for(int& e : routes[route])
                        {
                            if(e == target) return res;
                            q.push(e);
                        }
                    }
                }
            }
        }

        return -1;
    }
};
// @lc code=end

