/*
 * @lc app=leetcode.cn id=2641 lang=cpp
 *
 * [2641] 二叉树的堂兄弟节点 II
 */

// @lc code=start

//Definition for a binary tree node.
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    void bfs(TreeNode* root)
    {
        vector<TreeNode*> q;
        int depth = 0;
        root->val = 0;
        int prev = 0; // 保存上一层的结束位置，下一层从上一层结束开始枚举
        q.push_back(root);
        cout << q.size() << endl;

        while(prev < q.size() /*q.size()*/)
        {
            int sum = 0;
            int size = q.size();
            // vector<TreeNode*> next;
            // 统计同一层所有节点的和
            for(int i = prev; i < size; i++)
            {
                if(q[i]->left)
                {
                    sum += q[i]->left->val;
                    q.push_back(q[i]->left);
                }
                if(q[i]->right)
                {
                    sum += q[i]->right->val;
                    q.push_back(q[i]->right);
                }
            }

            // 将节点的值替换为堂兄弟节点的和（堂兄弟节点所有和 - 兄弟节点的和)
            for(int i = prev; i < size; i++)
            {
                int childsum = (q[i]->left ? q[i]->left->val : 0) 
                + (q[i]->right ? q[i]->right->val : 0);
                if(q[i]->left) q[i]->left->val = sum - childsum;
                if(q[i]->right) q[i]->right->val = sum - childsum;
            }
            // q = move(next);
            prev = size;
            // cout << prev << endl;
        }
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        bfs(root);

        return root;
    }
};
// @lc code=end

