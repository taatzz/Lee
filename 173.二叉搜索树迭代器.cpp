/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */

// @lc code=start

// Definition for a binary tree node.
#include <vector>
#include <functional>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public: 
    vector<int> t;
    int idx = -1;
    BSTIterator(TreeNode* root) {
        function<void(TreeNode*)> dfs = [&](TreeNode* node)
        {
            if(!node) return;

            dfs(node->left);
            t.push_back(node->val);
            dfs(node->right);
        };
        dfs(root);
    }
    
    int next() {
        if(idx == t.size()) return -1;
        return t[++idx];
    }
    
    bool hasNext() {
        return idx == t.size() - 1 ? false : true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

