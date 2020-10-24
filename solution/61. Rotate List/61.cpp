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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        
        // 1. count list size
        auto *p = head, *tail = head;
        int n = 0;
        while (p) {
            ++n;
            tail = p;
            p = p->next;
        }
        k %= n;
        if (k == 0) return head;
        
        // 2. find the break point
        auto *pre = head, *cur = head;
        int left = n - k;
        while (left--) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = nullptr;
        
        // 3. concatenate two list
        tail->next = head;
        
        return cur;
    }
};
