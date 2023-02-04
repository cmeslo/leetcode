# 234. Palindrome Linked List

1. 用快慢指針找到中點，斷開成兩條 list - A, B
2. 反轉 list B
3. 最後逐一比較 list A 與 list B。

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        auto slow = head, fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast) // for odd
            slow = slow->next;
        
        slow = reverseList(slow);
        
        while (slow) {
            if (slow->val != head->val) return false;
            slow = slow->next;
            head = head->next;
        }
        
        return true;
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
```
