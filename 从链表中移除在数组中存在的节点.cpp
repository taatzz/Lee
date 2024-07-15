#include <vector>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> h;
        int n = nums.size();
        for(int i = 0; i < n; i++) h.insert(nums[i]);

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* cur = head;

        while(cur)
        {
            if(h.count(cur->val))
            {
                pre->next = cur->next;
            }
            else pre = pre->next;
            cur = cur->next;
        }

        return dummy->next;
    }
};