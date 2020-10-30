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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        auto *slow = head, *fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto *mid = slow->next;
        slow->next = nullptr;
        
        return merge(sortList(head), sortList(mid));
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val > l2->val) swap(l1, l2);
            tail->next = l1;
            tail = tail->next;
            l1 = l1->next;
        }
        tail->next = l1 ? l1 : l2;
        
        return dummy.next;
    }
};
