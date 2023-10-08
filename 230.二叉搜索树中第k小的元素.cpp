/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */

// @lc code=start

//Definition for a binary tree node.
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
    vector<int> tmp;
    void dfs(TreeNode* root)
    {
        if(!root)
            return;

        dfs(root->left);
        tmp.push_back(root->val);
        dfs(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {

        dfs(root);

        return tmp[k - 1];
    }
};
// @lc code=end

