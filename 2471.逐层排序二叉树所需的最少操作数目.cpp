/*
 * @lc app=leetcode.cn id=2471 lang=cpp
 *
 * [2471] 逐层排序二叉树所需的最少操作数目
 */

// @lc code=start

// Definition for a binary tree node.
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <unordered_map>

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
    static const int N = 100010;
    int a[N];
    bool st[N];

    void find(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> h;
        for(int i = 0; i < nums.size(); i++) h[nums[i]] = i;

        for(int i = 0; i < nums.size(); i++)
        {
            while(a[i] != nums[i])
            {
                swap(a[i], a[h[a[i]]]);
                res++;
            }
        }
    }

    void bfs(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);

        while(q.size())
        {
            int n = q.size();
            memset(st, 0, sizeof st);
            int idx = 0;
            vector<int> t;
            for(int i = 0; i < n; i++) 
            {
                a[idx++] = q.front()->val;
                t.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            find(t);
        }
    }

    int minimumOperations(TreeNode* root) {
        bfs(root);

        return res;
    }
};
// @lc code=end

