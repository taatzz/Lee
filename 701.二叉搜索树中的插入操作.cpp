/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        {
            root = new TreeNode(val);
            return root;
        }
        TreeNode* parent = nullptr;
        TreeNode* cur = root;
        while(cur)
        {
            if(cur->val > val)
            {
                parent = cur;
                cur = cur->left;
            }
            else
            {
                parent = cur;
                cur = cur->right;
            }
        }
        if(parent->val > val)
        {
            TreeNode* newnode = new TreeNode(val);
            parent->left = newnode;
        }
        else
        {
            TreeNode* newnode = new TreeNode(val);
            parent->right = newnode;
        }
        return root;
    }
};
// @lc code=end

