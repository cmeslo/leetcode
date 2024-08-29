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

        unordered_map<int, ListNode*> m;
        auto i = &dummy, j = &dummy;
        int sum = 0;
        while (j) {
            sum += j->val;
            if (m.count(sum)) {
                m[sum]->next = j->next;
                return removeZeroSumSublists(dummy.next);
                // i = j->next;
            }
            m[sum] = j;
            j = j->next;
        }
        return dummy.next;
    }
};

// x x x [x x x] x x


