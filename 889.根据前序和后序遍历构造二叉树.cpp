/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode* dfs(vector<int>& pre, vector<int>& post, int l1, int r1, int l2, int r2)
    {
        if(l1 > r1) return nullptr;
        if(l1 == r1)
        {
            TreeNode* newnode = new TreeNode(pre[l1]);
            return newnode;
        }

        TreeNode* newnode = new TreeNode(pre[l1]);
        int idx = 0;
        for(int i = l2; i <= r2; i++)
        {
            if(post[i] == pre[l1 + 1])
            {
                idx = i;
                break;
            }
        }

        int left = idx - l2 + 1;
        newnode->left = dfs(pre, post, l1 + 1, l1 + left, l2, idx);
        newnode->right = dfs(pre, post, l1 + left + 1, r1, idx + 1, r2 - 1);

        return newnode;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        return dfs(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
    }
};
// @lc code=end

