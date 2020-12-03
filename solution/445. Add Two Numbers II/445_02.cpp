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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode *ans = nullptr;
        ListNode *cur = nullptr;
        int carry = 0;
        while (l1 || l2 || carry) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            
            int sum = a + b + carry;
            if (!cur) {
                cur = new ListNode(sum % 10);
                ans = cur;
            } else {
                cur->next = new ListNode(sum % 10);
                cur = cur->next;
            }
            carry = sum / 10;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        
        return reverseList(ans);
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            auto *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
