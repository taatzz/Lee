/*
 * @lc app=leetcode.cn id=2583 lang=cpp
 *
 * [2583] 二叉树中的第 K 大层和
 */

// @lc code=start

// Definition for a binary tree node.
#include <vector>
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

class Solution {
public:
    vector<long long> res;

    void bfs(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);

        while(q.size())
        {
            int n = q.size();
            long long sum = 0;
            for(int i = 0; i < n; i++)
            {
                auto t = q.front();
                q.pop();
                sum += t->val;

                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            res.push_back(sum);
        }
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        bfs(root);
        sort(res.begin(), res.end(), greater<long long>());

        return res.size() < k ? -1 : res[k - 1];
    }
};
// @lc code=end

