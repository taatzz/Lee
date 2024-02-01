/*
 * @lc app=leetcode.cn id=2385 lang=cpp
 *
 * [2385] 感染二叉树需要的总时间
 */

// @lc code=start

// Definition for a binary tree node.
#include <cstring>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    static const int N = 100010;
    int h[N], e[N * 2], ne[N  * 2], idx = 0;
    int dist[N], res;

    void add(int a,int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    void dfs(TreeNode* root)
    {
        if(!root)
            return;

        if(root->left)
        {
            int a = root->val, b = root->left->val;
            add(a, b), add(b, a);
            dfs(root->left);
        }
        if(root->right)
        {
            int a = root->val, b = root->right->val;
            add(a, b), add(b, a);
            dfs(root->right);
        }
    }

    void bfs(int start)
    {
        memset(dist, -1, sizeof dist);
        queue<int> q;
        q.push(start);
        dist[start] = 0;

        while(q.size())
        {
            int t = q.front();
            q.pop();
            
            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                if(dist[j] == -1)
                {
                    dist[j] = dist[t] + 1;
                    q.push(j);
                    res = max(res, dist[j]);
                }
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        memset(h, -1, sizeof h);
        dfs(root);

        bfs(start);

        return res;
    }
};
// @lc code=end

