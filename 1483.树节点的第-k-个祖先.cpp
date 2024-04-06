/*
 * @lc app=leetcode.cn id=1483 lang=cpp
 *
 * [1483] 树节点的第 K 个祖先
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class TreeAncestor {
public:
    vector<vector<int>> pa;

    TreeAncestor(int n, vector<int>& parent) {
        int m = 32 - __builtin_clz(n);
        pa.resize(n, vector<int>(m, -1));

        for(int i = 0; i < parent.size(); i++)
        {
            pa[i][0] = parent[i];
        }

        for(int i = 1; i <= m - 1; i++)
        {
            for(int x = 0; x < n; x++)
            {
                int p = pa[x][i - 1];
                if(p != -1) pa[x][i] = pa[p][i - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(; k && node != -1; k &= k - 1)
            node = pa[node][__builtin_ctz(k)];

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
// @lc code=end

