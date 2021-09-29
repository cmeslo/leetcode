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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *L = &dummy, *R = nullptr;
        ListNode *l = nullptr, *r = nullptr;
        L->next = head;
        // L l . . . r R ==> L r . . . l R
        
        // find L, l
        auto cur = &dummy;
        for (int i = 0; i < left - 1; ++i)
            cur = cur->next;
        L = cur;
        l = cur = cur->next;
        
        // find r, R and reverse
        for (int i = left; i <= right; ++i) {
            R = cur->next;
            cur->next = r;
            r = cur;
            cur = R;
        }
        
        L->next = r;
        l->next = R;
        
        return dummy.next;
    }
};
