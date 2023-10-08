/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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

    void dfs(TreeNode* root, int num)
    {
        if(!root)
        {
            res = max(num, res);
            return;
        }

        num++;
        dfs(root->left, num);
        dfs(root->right, num);
    }

    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        

        return res;
    }
};
// @lc code=end

