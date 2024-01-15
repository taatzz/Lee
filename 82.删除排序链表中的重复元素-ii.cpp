/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        else if(head->next == nullptr) return head;

        ListNode* dummynode = new ListNode();
        dummynode->next = head;
        ListNode* cur = dummynode;

        while(cur->next && cur->next->next)
        {
            int val = cur->next->val;
            if(cur->next->next->val == val)
            {
                while(cur->next && cur->next->val == val)
                {
                    cur->next = cur->next->next;
                }
            }
            else cur = cur->next;
        }

        return dummynode->next;
    }
};
// @lc code=end

