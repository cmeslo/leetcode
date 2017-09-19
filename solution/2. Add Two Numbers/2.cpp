/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode(0);
        ListNode* index = sum;
        int carry = 0;
        
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL) {
                index->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                index->val += l2->val;
                l2 = l2->next;
            }
            carry = index->val / 10;
            index->val = index->val % 10;
            if (l1 != NULL || l2 != NULL || carry != 0) {
                index->next = new ListNode(carry);
                index = index->next;
            }
        }
        return sum;
    }
};
