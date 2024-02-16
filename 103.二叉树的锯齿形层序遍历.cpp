/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

// @lc code=start

// Definition for a binary tree node.
#include <vector>
#include <queue>

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
    vector<vector<int>> res;

    void bfs(TreeNode* root)
    {
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size())
        {
            int n = q.size();
            vector<int> tmp;

            for(int i = 0; i < n; i++)
            {
                auto t = q.front();
                q.pop();
                tmp.push_back(t->val);

                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            res.push_back(tmp);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bfs(root);

        for(int i = 0; i < res.size(); i++)
        {
            if(i % 2 == 1) reverse(res[i].begin(), res[i].end()); 
        }

        return res;
    }
};
// @lc code=end

