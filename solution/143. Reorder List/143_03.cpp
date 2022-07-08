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
        vector<int> A;
        auto p = head;
        while (p) {
            A.push_back(p->val);
            p = p->next;
        }
        int i = 0, j = A.size() - 1;
        bool flag = true;
        while (i <= j) {
            if (flag)
                head->val = A[i++];
            else
                head->val = A[j--];
            flag = !flag;
            head = head->next;
        }
    }
};
