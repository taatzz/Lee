/*
 * @lc app=leetcode.cn id=1367 lang=cpp
 *
 * [1367] 二叉树中的链表
 */

// @lc code=start

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
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
    bool flag = false;
    ListNode* _head;

    void dfs(TreeNode* root, ListNode* head)
    {
        if(!head) flag = true;
        if(!root || flag)
        {
            return;
        }

        if(root->val == head->val)
        {
            dfs(root->left, head->next);
            dfs(root->right, head->next);
        }
        else
        {
            dfs(root->left, _head);
            dfs(root->right, _head);
        }
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        _head = head;
        dfs(root, head);
        if(root->left) isSubPath(head, root->left);
        if(root->right) isSubPath(head, root->right);

        return flag;
    }
};
// @lc code=end

