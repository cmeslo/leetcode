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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto a = headA, b = headB;
        while (a) {
            a->val *= -1;
            a = a->next;
        }
        
        ListNode* ans = nullptr;
        while (b) {
            if (!ans && b->val < 0) {
                ans = b;
                break;
            }
            b = b->next;
        }
        
        a = headA;
        while (a) {
            a->val *= -1;
            a = a->next;
        }
        return ans;
    }
};
