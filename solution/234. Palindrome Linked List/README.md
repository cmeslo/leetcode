# 234. Palindrome Linked List

1. 用快慢指針找到中點，斷開成兩條 list - A, B
2. 反轉 list B
3. 最後逐一比較 list A 與 list B。

```cpp
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
```
