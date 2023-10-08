/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

// @lc code=start

//Definition for a binary tree node.
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
    TreeNode* prev;
    TreeNode* target1;
    TreeNode* target2;
    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        dfs(root->left);
        if(prev)
        {
            if(root->val <= prev->val)
            {
                if(!target1)
                {
                    target1 = prev;
                    target2 = root;
                }
                else target2 = root;
            }
        }
        prev = root;
        dfs(root->right);
    }

    void recoverTree(TreeNode* root) {
        dfs(root);

    }
};
// @lc code=end

