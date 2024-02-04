/*
 * @lc app=leetcode.cn id=1145 lang=cpp
 *
 * [1145] 二叉树着色游戏
 */

// @lc code=start

// Definition for a binary tree node
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
    int l, r, _x;

    int dfs(TreeNode* root)
    {
        if(!root)
            return 0;

        int ls = dfs(root->left);
        int rs = dfs(root->right);
        if(root->val == _x)
            l = ls, r = rs;

        return ls + rs + 1;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        _x = x;

        dfs(root);

        // 左子树 右子树 剩余的点 乘2大于n就说明大于一半
        return std::max( {l, r, n - 1 - l - r} ) * 2 > n;
    }
};
// @lc code=end

