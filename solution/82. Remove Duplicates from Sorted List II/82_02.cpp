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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode dummy(0);
        auto cur = &dummy;
        
        auto tmp = head;
        while (tmp && head->val == tmp->val)
            tmp = tmp->next;
        
        if (head->next == tmp) {
            head->next = deleteDuplicates(tmp);
            cur->next = head;
        } else {
            cur->next = deleteDuplicates(tmp);
        }
        return dummy.next;
    }
};
