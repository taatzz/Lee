/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start

// Definition for a Node.
#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                auto a = q.front();
                q.pop();
                if(i < n - 1)
                    a->next = q.front();
                if(a->left)
                    q.push(a->left);
                if(a->right)
                    q.push(a->right);
            }
        }
        return root;
    }
};
// @lc code=end

