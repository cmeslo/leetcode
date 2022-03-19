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
        vector<int> A;
        while (head) {
            if (head->val == 0)
                A.push_back(head->val);
            else {
                if (A.back() == 0)
                    A.push_back(head->val);
                else
                    A.back() += head->val;
            }
            head = head->next;
        }
        ListNode dummy;
        auto pre = &dummy;
        for (int x : A) {
            if (x == 0) continue;
            pre->next = new ListNode(x);
            pre = pre->next;
        }
        return dummy.next;
    }
};
