/*
 * @lc app=leetcode.cn id=1379 lang=cpp
 *
 * [1379] 找出克隆二叉树中的相同节点
 */

// @lc code=start

// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* target)
    {
        if(!root) return nullptr;

        if(root->val == target->val) return root;
        auto left = dfs(root->left, target);
        auto right = dfs(root->right, target);

        if(left) return left;
        else return right;
        
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        return dfs(cloned, target);
    }
};
// @lc code=end

