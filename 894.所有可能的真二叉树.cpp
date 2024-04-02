/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的真二叉树
 */

// @lc code=start

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
    vector<TreeNode*> f[15];
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0) return {};
        

        f[1] = {new TreeNode()};
        for(int i = 2; i < 11; i++)
        {
            for(int j = 1; j < i; j++)
            {
                for(auto left : f[j])
                {
                    for(auto right : f[i - j])
                        f[i].push_back(new TreeNode(0, left, right));
                }
            }
        }

        return f[(n + 1) / 2];
    }
};
// @lc code=end

