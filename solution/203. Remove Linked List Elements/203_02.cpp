/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val)
            head = head->next;
        auto cur = head;
        while (cur) {
            auto p = cur->next;
            while (p && p->val == val)
                p = p->next;
            cur->next = p;
            cur = cur->next;
        }
        return head;
    }
};
