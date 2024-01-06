/*
 * @lc app=leetcode.cn id=2476 lang=cpp
 *
 * [2476] 二叉搜索树最近节点查询
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
    vector<int> tmp;

    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        dfs(root->left);
        tmp.push_back(root->val);
        dfs(root->right);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> res;

        dfs(root);
        
        for(auto e : queries)
        {
            vector<int> t(2);
            int x = lower_bound(tmp.begin(), tmp.end(), e) - tmp.begin();
            if(x == tmp.size()) 
            {
                t[0] = tmp[tmp.size() - 1];
                t[1] = -1;
            }
            else
            {
                if(tmp[x] == e)
                {
                    t[0] = e;
                    t[1] = e;
                }
                else
                {
                    if(x == 0)
                    {
                        t[0] = -1;
                        t[1] = tmp[x];
                    }
                    else
                    {
                        t[0] = tmp[x - 1];
                        t[1] = tmp[x];
                    }
                }
            }
            res.push_back(t);
        }

        return res;
    }
};
// @lc code=end

