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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        auto tail = &dummy;
        
        auto pre = head;
        while (pre) {
            auto cur = pre->next;
            
            while (cur && pre->val == cur->val)
                cur = cur->next;
            
            if (pre->next == cur) 
                tail = tail->next = pre;
            
            pre = cur;
        }
        tail->next = nullptr;
        
        return dummy.next;
    }
};
