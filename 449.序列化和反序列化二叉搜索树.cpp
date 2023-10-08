/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */

// @lc code=start

// Definition for a binary tree node.
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {} };

class Codec{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            char x = t->val - '0';
            
            s += x;
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        return s;
    }

    // Decodes your encoded data to tree.

    TreeNode* Insert(TreeNode* root, int x)
    {
        if(root == nullptr)
        {
            root = new TreeNode(x);
        }

        TreeNode* cur = root;
        TreeNode* parent = nullptr;
        while(cur)
        {
            if(cur->val > x)
            {
                parent = cur;
                cur = cur->left;
            }
            else
            {
                parent = cur;
                cur = cur->right;
            }
        }
        cur = new TreeNode(x);
        if(parent->val > x)
            parent->left = cur;
        else
            parent->right = cur;

        return root;
    }

    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        for(int i = 0; i < data.size(); i++)
        {
            int tmp = data[i] - '0';
            root = Insert(root, tmp);
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

