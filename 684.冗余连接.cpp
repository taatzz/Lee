/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> res;

    int find(vector<int>& p, int x)
    {
        if(x != p[x])
            p[x] = find(p, p[x]); // 路径压缩将所有子节点指向根节点
        return p[x];
    }

    // 无向图
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        for(int i = 1; i <= n; i++)parent[i] = i; // init

        for(int i = 0; i < n; i++)
        {
            // 找到当前节点的根节点
            int a = find(parent, edges[i][0]), b = find(parent, edges[i][1]);

            // 相同时表示当前的节点表示有相同的节点，表示当前的集合已经添加了当前的元素，不操作
            if(a == b)
            {
                res.push_back(edges[i][0]);
                res.push_back(edges[i][1]);
                return res;
            }
            else // 将子节点指向父节点
                parent[a] = b;
        }

        return res;
    }
};
// @lc code=end

