# 876. Middle of the Linked List

```cpp
ListNode* middleNode(ListNode* head) {
    auto slow = head, fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```
