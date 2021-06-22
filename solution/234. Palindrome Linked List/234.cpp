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
    bool isPalindrome(ListNode* head) {
        auto *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast) { // for odd
            slow = slow->next;
        }
        
        slow = reverseList(slow);
        
        while (slow) {
            if (slow->val != head->val) return false;
            head = head->next;
            slow = slow->next;
        }
        
        return true;
    }

private:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};
