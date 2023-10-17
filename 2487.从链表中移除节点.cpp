/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 *
 * [2487] 从链表中移除节点
 */

// @lc code=start

// Definition for singly-linked list.
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stk;

        ListNode* cur = head;
        while(cur)
        {
            while(!stk.empty() && stk.top()->val < cur->val)
            {
                stk.pop();
            }
            stk.push(cur);
            cur = cur->next;
        }

        ListNode* dummynode = new ListNode();
        while(!stk.empty())
        {
            stk.top()->next = dummynode->next;
            dummynode->next = stk.top();
            stk.pop();
        }

        return dummynode->next;
    }
};
// @lc code=end

