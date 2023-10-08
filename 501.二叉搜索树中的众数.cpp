/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */

// @lc code=start

// Definition for a binary tree node.
#include <iostream>
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
    vector<int> res;
    int maxcount = 0;
    int count = 0;
    TreeNode* prev;
    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        
        dfs(root->left);
        if(prev == nullptr)
            count = 1;
        else if(prev->val == root->val)
            count ++;
        else
            count = 1;
        
        if(count == maxcount)
        {
            res.push_back(root->val);
        }

        if(count > maxcount)
        {
            maxcount = count;
            res.clear();
            res.push_back(root->val);
        }

        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);

        return res;
    }
};
// @lc code=end

