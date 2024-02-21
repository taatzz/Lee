/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

// @lc code=start

// Definition for a binary tree node.
#include <vector>

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
    TreeNode* dfs(vector<int>& post, vector<int>& in, int l1, int r1, int l2, int r2)
    {
        if(l1 < r1)
            return nullptr;
        if(l1 == r1)
        {
            TreeNode* newnode = new TreeNode(post[l1]);
            return newnode;
        }

        int idx = 0;
        for(int i = l2; i <= r2; i++)
        {
            if(in[i] == post[l1])
            {
                idx = i;
                break;
            }
        }
        int right = r2 - idx;
        TreeNode* newnode = new TreeNode(post[l1]);
        newnode->left = dfs(post, in, l1 - right - 1, r1, l2, idx - 1);
        newnode->right = dfs(post, in, l1 - 1, l1 - right, idx + 1, r2);

        return newnode;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        return dfs(postorder, inorder, postorder.size() - 1, 0, 0, inorder.size() - 1);
    }
};
// @lc code=end

