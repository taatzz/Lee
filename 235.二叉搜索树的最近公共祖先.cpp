/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start

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
        if(!root) return nullptr;
        if(root->val == p->val || root->val == q->val) return root;

        auto left = dfs(root->left, p, q);
        auto right = dfs(root->right, p, q);

        if(left && right) return root;
        else if(left || right)
        {
            if(left) return left;
            else return right;
        }

        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return dfs(root, p, q);
    }
};
// @lc code=end

