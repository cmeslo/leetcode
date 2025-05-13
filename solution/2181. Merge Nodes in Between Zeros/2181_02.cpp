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
    ListNode* mergeNodes(ListNode* head) {
        for (auto p1 = head, p2 = head->next; p2; p2 = p2->next) {
            if (p2->val != 0) {
                p1->val += p2->val;
            } else {
                p1->next = p2->next ? p2 : nullptr;
                p1 = p2;
            }
        }
        return head;
    }
};


// 0   1   0
// ^   ^
// p1  p2


// 0   1   0
// ^       ^
// p1      p2
