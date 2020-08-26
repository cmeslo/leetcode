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
    void reorderList(ListNode* head) {
        if (!head) return;
        
        // 1. find the middle node
        auto *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 2. cut and reverse the second list
        ListNode *head2 = nullptr;
        ListNode *last = slow->next;
        slow->next = nullptr;
        while (last) {
            auto *tmp = last->next;
            last->next = head2;
            head2 = last;
            last = tmp;
        }
        
        // 3. merge two list
        while (head && head2) {
            auto *tmp1 = head->next, *tmp2 = head2->next;
            head->next = head2;
            head2->next = tmp1;
            head = tmp1;
            head2 = tmp2;
        }
    }
};
