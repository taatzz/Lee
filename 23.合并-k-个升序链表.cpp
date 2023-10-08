/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

// @lc code=start

// Definition for singly-linked list.
#include <vector>

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

    void _insert(ListNode*& dummy, ListNode*& tmp)
    {
        ListNode* cur = dummy->next;
        ListNode* t = tmp;
        while(cur->next && t)
        {
            if(cur->val > t->val)
                cur = cur->next;
            else
            {
                ListNode* next = t->next;
                t->next = cur->next;
                cur->next = t;
                cur = cur->next;
                t = next;
            }
        }
        if(t)
        {
            cur->next = t;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;

        ListNode* dummynode = new ListNode();
        dummynode->next = lists[0];
        for(int i = 1; i < lists.size(); i++)
        {
            _insert(dummynode, lists[i]);
        }

        return dummynode->next;
    }
};
// @lc code=end

