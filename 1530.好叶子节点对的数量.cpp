/*
 * @lc app=leetcode.cn id=1530 lang=cpp
 *
 * [1530] 好叶子节点对的数量
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Definition for a binary tree node.
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
    int res = 0;
    vector<int> dfs(TreeNode* root, int k)
    {
        if(!root) return{};
        // 叶子节点返回
        if(root->left == nullptr && root->right == nullptr) return {0};

        vector<int> cnt;
        // 向上归时，遇到一个祖先节点深度就加一
        auto left = dfs(root->left, k);
        for(auto& e : left)
        {
            if(++e > k) continue;
            cnt.push_back(e);
        }
        auto right = dfs(root->right, k);
        for(auto& e : right)
        {
            if(++e > k) continue;
            cnt.push_back(e);
        }

        // 每个人节点作为父节点时的叶子节点的最短距离就是深度相加
        for(auto l : left)
        {
            for(auto r : right)
                res += (l + r <= k);
        }

        return cnt;
    }

    int countPairs(TreeNode* root, int k) {
        dfs(root, k);

        return res;
    }
};
// @lc code=end

