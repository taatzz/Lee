/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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
    TreeNode* node;
    int cnt = 0;

    pair<TreeNode*, int> dfs(TreeNode* root)
    {
        if(!root)
            return {root, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if(left.second > right.second)
            return {left.first, left.second + 1};

        if(left.second < right.second)
            return { right.first, right.second + 1 };

        return {root, left.second + 1};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root){
        return dfs(root).first;
    }
};
// @lc code=end

