/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int res = 0;

    int dfs(TreeNode* root)
    {
        if(!root)
            return 2;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if(left == 2&& right == 2)
            return 0;

        if(left == 0 || right == 0)
        {
            res++;
            return 1;
        }

        if(left == 1 || right == 1)
            return 2;

        return -1;
    }

    int minCameraCover(TreeNode* root) {
        if(dfs(root) == 0)
            res++;

        return res;
    }
};
// @lc code=end

