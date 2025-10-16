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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto p = head;
        while (p && p->next) {
            auto tmp = new ListNode(gcd(p->val, p->next->val));
            tmp->next = p->next;
            p->next = tmp;
            p = tmp->next;
        }
        return head;
    }
};
