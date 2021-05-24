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
    ListNode* swapNodes(ListNode* head, int k) {
        auto p = head;
        ListNode *p1 = nullptr, *p2 = head;
        while (--k)
            p = p->next;
        p1 = p;
        
        while (p->next) {
            p = p->next;
            p2 = p2->next;
        }
        
        swap(p1->val, p2->val);
        return head;
    }
};
