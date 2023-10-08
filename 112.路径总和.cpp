/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

// @lc code=start

// * Definition for a binary tree node.
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
    int sum = 0;
    int res = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        dist(root, targetSum);

        return res;
    }

    void dist(TreeNode* root, int x)
    {
        if(!root)
            return;
        // 叶子节点
        if((root->left == nullptr && root->right == nullptr)
        || res == 1)
        {
            if(sum == x)
                res = 1;
            return;
        }

        sum += root->val;

        dist(root->left, x);
        dist(root->right, x);
        sum -= root->val;
    }
};
// @lc code=end

