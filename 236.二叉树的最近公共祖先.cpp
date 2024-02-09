/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start

//Definition for a binary tree node.

// Definition for a binary tree node.
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root)
            return NULL;
        if(root->val == p->val) return root;
        if(root->val == q->val) return root;

        auto left = dfs(root->left, p, q);
        auto right = dfs(root->right, p, q);

        if(left && right)
            return root;
        else if(left || right)
        {
            if(left) return left;
            if(right) return right;
        }
        else return NULL;

        return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return dfs(root, p, q);
    }
};
// @lc code=end

