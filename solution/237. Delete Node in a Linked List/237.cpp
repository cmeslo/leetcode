/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // 寫法一
        // node->val = node->next->val;
        // node->next = node->next->next;
        
        // 寫法二
        ListNode* tmp = node->next;
        *node = *(node->next);
        delete tmp;
        
        // 寫法二
        // *node = *(node->next);
        
        // 寫法四
        // node->val = node->next->val;
        // ListNode *tmp = node->next;
        // node->next = tmp->next;
        // delete tmp;
    }
};
