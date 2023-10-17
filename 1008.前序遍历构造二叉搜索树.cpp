/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
 */

// @lc code=start

// Definition for a binary tree node.
#include <vector>
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
    void insert(TreeNode* root, int val)
    {
        TreeNode* cur = root;
        TreeNode* parent = nullptr;

        while(cur)
        {
            parent = cur;
            if(cur->val > val)
                cur = cur->left;
            else
                cur = cur->right;
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
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        for(int i = 1; i < preorder.size(); i++)
        {
            insert(root, preorder[i]);
        }

        return root;
    }
};
// @lc code=end

