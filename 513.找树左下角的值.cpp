/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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

    void dfs(TreeNode* root, int depth, int prev)
    {
        if(!root)
            return;
        if(root->left && !root->left->left &&
            !root->left->right)
        {
            if(depth + 1 > prev)
            {
                res = root->left->val;
                prev = depth + 1;
            }
        }

        dfs(root->left, depth + 1, prev);
        dfs(root->right, depth + 1, prev);
    }

    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0, 0);

        return res;
    }
};
// @lc code=end

