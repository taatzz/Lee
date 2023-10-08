/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start

// Definition for a binary tree node.
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string res;
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            if(!t)
            {
                res += 'n';
                continue;
            }
            res += to_string(t->val);
            if(t->left)
                q.push(t->left);
            else 
                q.push(nullptr);
            
            if(t->right)
                q.push(t->right);
            else
                q.push(nullptr);
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> tmp;

        for(auto e : data)
        {
            if(e != 'n')
            {
                TreeNode* newnode = new TreeNode(e - '0');
                tmp.push_back(newnode);
            }
            else 
                tmp.push_back(nullptr);
        }
        TreeNode* cur = tmp[0];
        for(int i = 0; i < tmp.size(); i++)
        {
            int left = 2 * i + 1, right = left + 1;
            if(left < tmp.size())
                cur->left = tmp[left];
            if(right < tmp.size())
                cur->right = tmp[right];
            cur = tmp[i + 1];
        }

        return tmp[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

