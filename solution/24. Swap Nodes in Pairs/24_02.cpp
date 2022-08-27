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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        auto pre = &dummy, cur = head;
        while (cur && cur->next) {
            auto tmp = cur->next;
            pre->next = tmp;
            
            cur->next = tmp->next;
            tmp->next = cur;
            
            pre = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};

// 0 1 2 3 4
// p c t

// 0 2 1 3 4
// p t c

