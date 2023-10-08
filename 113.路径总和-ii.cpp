/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<int> path;
    vector<vector<int>> res;

    void dfs(TreeNode* root, int target)
    {
        if(!root->left && !root->right)
        {
            int sum = root->val;
            for(auto e : path)
                sum += e;
            if(sum == target)
                res.push_back(path);
        }

        path.push_back(root->val);
        if(root->left)
            dfs(root->left, target);

        if(root->right)
            dfs(root->right, target);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);

        return res;
    }
};
// @lc code=end

