/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode* dummynode = new ListNode();
        ListNode* prev = dummynode;
        ListNode* tail1 = head1;
        ListNode* tail2 = head2;

        while(tail1 && tail2)
        {
            if(tail1->val < tail2->val)
            {
                prev->next = tail1;
                tail1 = tail1->next;
                prev = prev->next;
            }
            else
            {
                prev->next = tail2;
                tail2 = tail2->next;
                prev = prev->next;
            }
        }
        if(tail1)
            prev->next = tail1;
        if(tail2)
            prev->next = tail2;

        ListNode* next = dummynode->next;
        delete dummynode;

        return next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;

        ListNode* head1 = sortList(head);
        ListNode* head2 = sortList(mid);

        return merge(head1, head2);
    }
};
// @lc code=end

