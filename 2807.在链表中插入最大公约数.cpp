/*
 * @lc app=leetcode.cn id=2807 lang=cpp
 *
 * [2807] 在链表中插入最大公约数
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
    int gcd(int a, int b)
    {
        return b ? gcd(b, a % b) : a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;

        while(cur->next)
        {
            int t = gcd(cur->val, cur->next->val);
            ListNode* newnode = new ListNode(t);
            newnode->next = cur->next;
            cur->next = newnode;
            cur = cur->next->next;
        }

        return head;
    }
};
// @lc code=end

