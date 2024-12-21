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
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode*> st;
        auto p = head;
        while (p) {
            st.push(p);
            p = p->next;
        }
        
        int carry = 0;
        while (!st.empty()) {
            auto node = st.top(); st.pop();
            carry += node->val * 2;
            node->val = carry % 10;
            carry /= 10;
        }
        
        if (carry) {
            auto res = new ListNode(carry);
            res->next = head;
            return res;
        }
        return head;
    }
};
