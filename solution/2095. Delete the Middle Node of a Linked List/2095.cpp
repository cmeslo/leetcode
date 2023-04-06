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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return nullptr;
        
        auto pre = head;
        auto a = head, b = head;
        while (b && b->next) {
            pre = a;
            a = a->next;
            b = b->next->next;
        }
        pre->next = a->next ? a->next : nullptr;
        return head;
    }
};
