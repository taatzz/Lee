/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

// @lc code=start

 // Definition for a binary tree node.
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
    int res;

    void bfs(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            res++;
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
    }

    int countNodes(TreeNode* root) {
        bfs(root);

        return res;
    }
};
// @lc code=end

