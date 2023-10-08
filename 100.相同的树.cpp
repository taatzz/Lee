/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start

 // Definition for a binary tree node.
 #include <queue>
 #include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  class Solution
  {
public:
    bool sametree(TreeNode *p, TreeNode *q)
    {
        queue<TreeNode *> s1;
        queue<TreeNode *> s2;

        s1.push(p);
        s2.push(q);

        while (!s1.empty() && !s2.empty())
        {
            TreeNode *t1 = s1.front();
            TreeNode *t2 = s2.front();
            s1.pop();
            s2.pop();

            if (t1 == nullptr && t2 == nullptr)
                continue;
            if (t1 == nullptr || t2 == nullptr)
                return false;
            if (t1->val != t2->val)
                return false;
            s1.push(t1->left);
            s1.push(t1->right);
            s2.push(t2->left);
            s2.push(t2->right);
        }

        if (!s1.empty() || !s2.empty())
            return false;
        return true;
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        return sametree(p, q);
    }
  };
// @lc code=end

