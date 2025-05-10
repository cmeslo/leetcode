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
        ListNode dummy;
        auto p = &dummy;
        int sum = 0;
        head = head->next;
        while (head) {
            if (head->val == 0) {
                p->next = new ListNode(sum);
                p = p->next;
                sum = 0;
            }
            sum += head->val;
            head = head->next;
        }
        return dummy.next;
    }
};
