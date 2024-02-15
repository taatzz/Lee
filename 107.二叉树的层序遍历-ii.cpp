/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */

// @lc code=start

// Definition for a binary tree node.
#include <vector>
#include <map>
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
    map<int, vector<int>> h;

    void bfs(TreeNode* root)
    {
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        int d = 0;

        while(q.size())
        {
            int n = q.size();

            for(int i = 0; i < n; i++)
            {
                auto t = q.front();
                q.pop();

                h[d].push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            d++;
        }
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        bfs(root);

        vector<vector<int>> res;
        for(auto it = h.rbegin(); it != h.rend(); it++) res.push_back((*it).second);

        return res;
    }
};
// @lc code=end

