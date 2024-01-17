/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
 */

// @lc code=start

// Definition for a binary tree node.
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> res;
    unordered_set<int> h;

    void dfs(TreeNode* root)
    {
        if(!root)
            return;

        dfs(root->left);
        dfs(root->right);

        if(root->left && h.count(root->left->val)) root->left = nullptr;
        if(root->right && h.count(root->right->val)) root->right = nullptr;

        if(h.count(root->val))
        {
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& nums) {
        for(auto e : nums) h.insert(e);

        dfs(root);
        if(h.find(root->val) == h.end()) res.push_back(root);

        return res;
    }
};
// @lc code=end

