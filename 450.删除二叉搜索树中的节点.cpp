/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    typedef TreeNode node;
    void move(TreeNode*& root, int key)
    {
        if(root)
            return;

        node* cur = root;
        node* parent = nullptr;
        while(cur)
        {
            if(cur->val > key)
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

        if(!cur->left && !cur->right)
        {
            if(!parent)
                root = NULL;
            else
            {
                if(parent && parent->left == cur)
                {
                    parent->left = nullptr;
                }
                else if(parent && parent->right == cur)
                {
                    parent->right = nullptr;
                }
            }
        }
        else if(!cur->left || !cur->right)
        {
            if(parent && parent->left == cur)
            {
                if(cur->left == nullptr)
                {
                    parent->left = cur->right;
                }
                else
                {
                    parent->left = cur->left;
                }
            }
            else if(parent && parent->right == cur)
            {
                if(cur->left == nullptr)
                {
                    parent->right = cur->right;
                }
                else
                {
                    parent->right = cur->left;
                }
            }
            else
            {
                if(cur->left == nullptr)
                    root = cur->right;
                else
                    root = cur->left;
            }
        }
        else
        {
            node* _left = cur->left;
            while(_left->right)
                _left = _left->right;
            int tmp = _left->val;
            move(root, _left->val);
            cur->val = tmp;
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        move(root, key);

        return root;
    }
};
// @lc code=end

