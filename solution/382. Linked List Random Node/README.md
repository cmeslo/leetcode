# 382. Linked List Random Node

## 382_01.cpp

Count the length of list.

```cpp
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        len = 0;
        
        while (head) {
            ++len;
            head = head->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int pos = rand() % len;
        
        auto *cur = head;
        while (pos-- > 0)
            cur = cur->next;
        
        return cur->val;
    }
    
private:
    ListNode *head;
    int len;
};
```
