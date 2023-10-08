/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start

 //Definition for a binary tree node.
 #include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    int res = 0x3f3f3f3f;
    void contdepth(TreeNode* root, int x)
    {
        if(!root)
        {
            res = min(x, res);
            return;
        }
        x++;
        contdepth(root->left, x);
        contdepth(root->right, x);
    }

    int minDepth(TreeNode* root) {
        return res;
    }
};
// @lc code=end

