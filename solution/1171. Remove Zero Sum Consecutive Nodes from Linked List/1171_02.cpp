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
        auto i = &dummy;
        int presum = 0;
        while (i) {
            presum += i->val;
            if (m.count(presum)) {
                auto j = m[presum]->next;
                m[presum]->next = i->next;
                int sum = presum + j->val;
                // while (j != i) {
                while (sum != presum) {
                    m.erase(sum);
                    j = j->next;
                    sum += j->val;
                }
            } else {
                m[presum] = i;
            }
            i = i->next;
        } 
        return dummy.next;
    }
};

// x x x [x x x] x x
//        j   i

