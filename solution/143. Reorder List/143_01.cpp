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
        
        deque<ListNode*> q;
        auto* cur = head;
        while (cur) {
            q.push_back(cur);
            cur = cur->next;
        }

        ListNode *p1 = nullptr, *p2 = nullptr;
        while (!q.empty()) {
            p1 = q.front(); q.pop_front();
            if (p2) p2->next = p1;
            if (q.empty()) {
                p1->next = nullptr;
                break;
            }
            
            p2 = q.back(); q.pop_back();
            p1->next = p2;
            if (q.empty()) {
                p2->next = nullptr;
                break;
            }
        }
    }
};
