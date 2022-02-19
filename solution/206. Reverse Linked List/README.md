# 206. Reverse Linked List

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode *pre = nullptr;
    while (head) {
        auto tmp = head->next;
        head->next = pre;
        pre = head;
        head = tmp;
    }
    return pre;
}
```
