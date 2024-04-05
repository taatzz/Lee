/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
    static const int INF = 1e5 + 10;

    pair<int, int> dfs(TreeNode* root)
    {
        if(!root)
            return {INT_MAX, INT_MIN};

        auto [l_mn, l_mx] = dfs(root->left);
        auto [r_mn, r_mx] = dfs(root->right);
        int mn = min(root->val, min(l_mn, r_mn));
        int mx = max(root->val, max(l_mx, r_mx));

        res = max(res, max(root->val - mn, mx - root->val));

        return {mn, mx};
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root);

        return res;
    }
};
// @lc code=end

