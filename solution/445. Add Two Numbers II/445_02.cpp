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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        ListNode dummy;
        auto p = &dummy;
        int a = 0, b = 0, carry = 0;
        while (l1 || l2 || carry) {
            a = 0, b = 0;
            if (l1) {
                a = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                b = l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode((a + b + carry) % 10);
            carry = (a + b + carry) / 10;
            p = p->next;
        }
        return reverse(dummy.next);
    }
    
    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        while (node) {
            auto next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};
