/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start

// Definition for a binary tree node.
#include <iostream>

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
    int res = 0;
    int dfs(TreeNode* root)
    {
        if(!root) return -1;

        int left = dfs(root->left) + 1;
        int right = dfs(root->right) + 1;

        res = max(res, left + right);

        return max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);

        return res;
    }
};
// @lc code=end

