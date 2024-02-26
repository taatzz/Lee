/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
    int dfs(TreeNode* root, int low, int high)
    {
        if(!root) return 0;

        int x = root->val;
        int sum = low <= x && x <= high ? x : 0;
        if(x > low) sum += dfs(root->left, low, high);
        if(x < high) sum += dfs(root->right, low, high);

        return sum;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return dfs(root, low, high);
    }
};
// @lc code=end

