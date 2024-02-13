/*
 * @lc app=leetcode.cn id=987 lang=cpp
 *
 * [987] 二叉树的垂序遍历
 */

// @lc code=start
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
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
    map<int, vector<pair<int, int>>> h;

    void dfs(TreeNode* root, int r, int c)
    {
        if(!root) return;

        dfs(root->left, r + 1, c - 1);
        dfs(root->right, r + 1, c + 1);

        h[c].push_back({r, root->val});
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        
        dfs(root, 0, 0);
        for(auto& [_, e] : h)
        {
            vector<int> t;
            sort(e.begin(), e.end());
            for(auto x : e)
                t.push_back(x.second);
            res.push_back(t);
        }

        return res;
    }
};
// @lc code=end

