/*
 * @lc app=leetcode.cn id=1080 lang=cpp
 *
 * [1080] 根到叶路径上的不足节点
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
    int k;

    bool dfs(TreeNode* root, int sum)
    {
        if(!root->left && !root->right)
        {
            if(root->val + sum < k)
                return 0;
            return 1;
        }

        int left = 0, right = 0;
        if(root->left)
            left = dfs(root->left, sum + root->val);
        if(root->right)
            right = dfs(root->right, sum + root->val);

        if(left == 0) root->left = nullptr;
        if(right == 0) root->right = nullptr;

        
        return right | left;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        k = limit;

        bool res = dfs(root, 0);
        if(res == 0) return nullptr;

        return root;
    }
};
// @lc code=end

