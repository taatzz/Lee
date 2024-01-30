/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
 */

// @lc code=start

// Definition for a binary tree node.
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

class CBTInserter {
public:
    TreeNode* _root;
    queue<TreeNode*> q;

    CBTInserter(TreeNode* root) {
        _root = root;
        queue<TreeNode*> t;
        t.push(_root);

        while(t.size())
        {
            auto a = t.front();
            t.pop();
            if(a->left == nullptr || a->right == nullptr)
            {
                q.push(a);
            }
            if(a->left) t.push(a->left);
            if(a->right) t.push(a->right);
        }
    }
    
    int insert(int val) {
        TreeNode* newnode = new TreeNode(val);

        while(q.size())
        {
            auto t = q.front();
            if(t->left && t->right)
                q.pop();
            else break;
        }

        if(q.front()->left == nullptr)
        {
            q.front()->left = newnode;
            q.push(newnode);
        }
        else if(q.front()->right == nullptr)
        {
            q.front()->right = newnode;
            q.push(newnode);
        }

        return q.front()->val;
    }
    
    TreeNode* get_root() {
        return _root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

