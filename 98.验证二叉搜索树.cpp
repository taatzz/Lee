/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    TreeNode *prev = nullptr;
    bool dfs(TreeNode* root)
    {
        if (!root)
            return true;

        if(!dfs(root->left))
            return false;
        if(prev == nullptr && root->left == nullptr)
            prev = root;
        
        if(prev->val >= root->val && prev != root)
            return false;

        prev = root;

        return dfs(root->right);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
};
// @lc code=end

