/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<int> >& g, vector<int>& s, int x)
    {
        if(g[x].size() == 0)
            return;

        for(int i = 0; i < g[x].size(); i++)
        {
            // 已经标记的房间表示正在搜索或者已经搜索完毕
            if(s[g[x][i]] == 1)
                continue;
            s[g[x][i]] = 1;
            dfs(g, s, g[x][i]);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int> st(n, 0);
        st[0] = 1;
        dfs(rooms, st, 0);

        for(int i = 0; i < n; i++)
            if(!st[i]) return false;
        
        return true;
    }
};
// @lc code=end

