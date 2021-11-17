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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;
        
        auto p = head;
        for (int t = 0; t < k; ++t) {
            if (!p) return head;
            p = p->next;
        }
        
        ListNode* pre = nullptr;
        auto cur = head;
        for (int i = 0; i < k && cur; ++i) {
            auto tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        head->next = reverseKGroup(cur, k);
        return pre;
    }
};
