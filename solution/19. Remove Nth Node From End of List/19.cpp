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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        auto fast = &dummy;
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        
        auto slow = &dummy;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        auto tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        
        return dummy.next;
    }
};
