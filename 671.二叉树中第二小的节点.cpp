/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
 */

// @lc code=start

// Definition for a binary tree node.
#include <vector>
#include <algorithm>
#include <set>

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
    set<int> res;
    // vector<int> res;

    void dfs(TreeNode* root)
    {
        if(root->left == nullptr)
        {
            res.insert(root->val);
            return;
        }
        
        dfs(root->left);
        dfs(root->right);

        //int t = min(root->left->val, root->right->val);
        res.insert(root->val);
        //root->val = t;
    }

    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        // sort(res.begin(), res.end());
        // res.erase(unique(res.begin(), res.end()), res.end());
        int t = *(++res.begin()); 

        return res.size() >= 2 ? t : -1;
    }
};
// @lc code=end

