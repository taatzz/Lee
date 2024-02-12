/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
// Definition for a binary tree node.
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     vector<int> res;

//     void non_post(TreeNode* root)
//     {
//         stack<TreeNode*> s;
//         s.push(root);

//         while(!s.empty())
//         {
//             auto t = s.top();
//             s.pop();
//             res.push_back(t->val);
//             if(t->left)
//                 s.push(t->left);
//             if(t->right)
//                 s.push(t->right);
//         }
//         reverse(res.begin(), res.end());
//     }

//     vector<int> postorderTraversal(TreeNode* root) {
//         non_post(root);
//         return res;
//     }
// };

class Solution {
public:
    vector<int> res;
    void dfs(TreeNode* root)
    {
        if(!root) return;

        dfs(root->left);
        dfs(root->right);
        res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);

        return res;
    }
};

// @lc code=end

