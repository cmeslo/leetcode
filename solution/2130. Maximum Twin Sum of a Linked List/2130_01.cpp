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
    int pairSum(ListNode* head) {
        vector<int> A;
        while (head) {
            A.push_back(head->val);
            head = head->next;
        }
        int res = 0;
        int i = 0, j = A.size() - 1;
        while (i < j) {
            res = max(res, A[i++] + A[j--]);
        }
        return res;
    }
};
