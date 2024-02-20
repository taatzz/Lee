/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* dfs(vector<int>& pre, vector<int>& in, int l1, int r1, int l2, int r2)
    {
        if(l1 > r1) return nullptr;

        if(l1 == r1)
        {
            TreeNode* newnode = new TreeNode(pre[l1]);
            return newnode;
        }

        int idx = l2, num = pre[l1];
        for(int i = l2; i <= r2; i++)
            if(in[i] == num)
            {
                idx = i;
                break;
            }
        TreeNode* newnode = new TreeNode(pre[l1]);
        int left = idx - l2;

        newnode->left = dfs(pre, in, l1 + 1, l1 + left, l2, idx - 1);
        newnode->right = dfs(pre, in, l1 + left + 1, r1, idx + 1, r2);

        return newnode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return dfs(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
// @lc code=end

