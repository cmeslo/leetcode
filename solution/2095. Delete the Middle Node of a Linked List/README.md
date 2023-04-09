# 2095. Delete the Middle Node of a Linked List

```cpp
ListNode* deleteMiddle(ListNode* head) {
    if (!head->next) return nullptr;

    auto pre = head;
    auto a = head, b = head;
    while (b && b->next) {
        pre = a;
        a = a->next;
        b = b->next->next;
    }
    pre->next = a->next ? a->next : nullptr;
    return head;
}
```
