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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        unordered_map<int, ListNode*> seen;
        auto i = &dummy;
        int presum = 0;
        for (auto i = &dummy; i; i = i->next) {
            presum += i->val;
            seen[presum] = i;
        }
        presum = 0;
        for (auto i = &dummy; i; i = i->next) {
            presum += i->val;
            i->next = seen[presum]->next;
        }
        return dummy.next;
    }
};

// x x x [x x x] x x
//        j   i

