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
        auto *tmp = head;
        int step = k;
        while (--step) {
            tmp = tmp->next;
        }
        auto *p1 = tmp;
        
        auto *p2 = head;
        while (tmp->next) {
            p2 = p2->next;
            tmp = tmp->next;
        }
        swap(p1->val, p2->val);
        return head;
    }
};
