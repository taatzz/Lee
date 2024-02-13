/*
 * @lc app=leetcode.cn id=2096 lang=cpp
 *
 * [2096] 从二叉树一个节点到另一个节点每一步的方向
 */

// @lc code=start

// Definition for a binary tree node.
#include <string>

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
    int s, d;
    string a, b, t, cur;

    bool dfs(TreeNode* root, int s)
    {
        if(!root) return false;
        if(root->val == s)
        {
            cur = t;
            return true;
        }
        
        t += 'L';
        dfs(root->left, s);
        t.pop_back();
        t += 'R';
        dfs(root->right, s);
        t.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int start, int dest) {
        s = start, d = dest;

        dfs(root, start);
        a = cur;
        cur.clear();
        t.clear();
        dfs(root, dest);
        b = cur;

        // 找到公共的前缀，相同的前缀是不用走的路
        int i = 0, j = 0;
        while(i < a.size() && j < b.size())
        {
            if(a[i] == b[j]) i++, j++;
            else break;
        }

        string res;
        // 前缀相同，start 是 end的父节点
        if(i == a.size()) return b.substr(j);
        else if(j == b.size()) // 前缀相同，start 是 end 的子节点
        {
            for(; i < a.size(); i++) res += 'U';
            return res;
        } 
        else
        {
            string res;
            // start只能往父节点走，所以就只有U
            for(; i < a.size(); i++) res += 'U';
            return res + b.substr(j);
        }

        return "";
    }
};
// @lc code=end

