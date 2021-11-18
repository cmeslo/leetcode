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
        int len = 0;
        auto p = head;
        while (p) {
            ++len;
            p = p->next;
        }
        
        ListNode* ans = head;
        ListNode* tail = head;
        int groups = len / k;
        for (int i = 0; i < groups; ++i) {
            ListNode* new_tail = head;
            ListNode* pre = nullptr;
            for (int j = 0; j < k; ++j) {
                auto tmp = head->next;
                head->next = pre;
                pre = head;
                head = tmp;
            }
            if (i == 0) ans = pre;
            tail->next = pre;
            tail = new_tail;
        }
        tail->next = head;
        return ans;
    }
};
