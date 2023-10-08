/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lc code=start

// Definition for a binary tree node.
#include <iostream>
#include <algorithm>

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
    int res;
    TreeNode* prev;
    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        dfs(root->left);
        if(prev != nullptr)
            res = min(res, root->val - prev->val);
        dfs(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        dfs(root);

        return res;
    }
};
// @lc code=end

