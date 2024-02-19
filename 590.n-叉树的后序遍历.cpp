/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
 */

// @lc code=start

// Definition for a Node.
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> res;

    void dfs(Node* root)
    {
        if(!root) return;

        for(auto e : root->children)
        {
            dfs(e);
        }

        res.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        dfs(root);

        return res;
    }
};
// @lc code=end

