/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

// @lc code=start

//Definition for a binary tree node.
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
    TreeNode* construst(vector<int>& num, int start, int end)
    {
        if(start > end)
            return nullptr;
        
        int maxindex = 0, maxval = -1;
        for(int i = start; i <= end; i++)
        {
            if(num[i] > maxval)
            {
                maxindex = i;
                maxval = num[i];
            }
        }
        TreeNode* root = new TreeNode(maxval);

        root->left = construst(num, 0, maxindex - 1);
        root->right = construst(num, maxindex + 1, end);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construst(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

