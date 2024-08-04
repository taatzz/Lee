/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 */

// @lc code=start

// Definition for a binary tree node.
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
    bool check(TreeNode* root, TreeNode* q)
    {
        if(!root || !q) return root == q;
        return root->val == q->val && check(root->left, q->left) && check(root->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* t) {
        if(!root) return false;

        return check(root, t) || isSubtree(root->left, t) || isSubtree(root->right, t);
    }
};
// @lc code=end

