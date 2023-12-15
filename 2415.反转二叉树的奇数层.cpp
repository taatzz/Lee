/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 *
 * [2415] 反转二叉树的奇数层
 */

// @lc code=start
// Definition for a binary tree node.
#include <queue>
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
    void bfs(TreeNode* root)
    {
        queue<TreeNode*> q;
        
        bool flag = 0;
        q.push(root);
        while(q.size())
        {
            int t = q.size();
            // vector保存所有的奇数层节点然后按照规则进行交换
            vector<TreeNode*> tmp;

            for(int i = 0; i < t; i++)
            {
                auto a = q.front();
                if(flag)
                    tmp.push_back(a);
                q.pop();
                if(a->left)
                    q.push(a->left);
                if(a->right)
                    q.push(a->right);
            }
            if(flag)
            {
                for(int i = 0, j = tmp.size() - 1; i < j; i++, j--)
                {
                    swap(tmp[i]->val, tmp[j]->val);
                }
            }
            tmp.clear();
            flag ^= 1;
        }
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        bfs(root);

        return root;
    }
};
// @lc code=end

