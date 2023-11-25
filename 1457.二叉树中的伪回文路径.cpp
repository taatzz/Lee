/*
 * @lc app=leetcode.cn id=1457 lang=cpp
 *
 * [1457] 二叉树中的伪回文路径
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
    int res = 0;

    void dfs(TreeNode* root, int cnt)
    {
        if(!root->right && !root->left)
        {
            cnt ^= 1 << root->val;
            if(cnt == (cnt & -cnt))
                res++;
            return;
        }

        if(root->left) dfs(root->left, cnt ^ (1 << root->val));
        if(root->right) dfs(root->right, cnt ^ (1 << root->val));
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root, 0);

        return res;
    }
};
// @lc code=end

