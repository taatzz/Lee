/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int> > res;

    void dfs(vector<vector<int> >& g, int x)
    {
        // 从 0 到 n-1的所有路径（没有到达n-1的路径不算）
        if(x == g.size() - 1)
        {
            res.push_back(path);
            return;
        }

        for(int i = 0; i < g[x].size(); i++)
        {
            path.push_back(g[x][i]);
            dfs(g, i);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        dfs(graph, 0);

        return res;
    }
};
// @lc code=end

