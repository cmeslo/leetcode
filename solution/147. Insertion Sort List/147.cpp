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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        
        while (head) {
            auto *tmp = head->next;
            auto *cur = &dummy;
            while (cur->next && cur->next->val <= head->val)
                cur = cur->next;
            
            head->next = cur->next;
            cur->next = head;
            head = tmp;
        }
        
        return dummy.next;
    }
};
